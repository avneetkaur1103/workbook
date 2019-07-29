import sys
import math
import random
from copy import copy, deepcopy

def debug(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)

moves = {'UP':(0, -1), 'DOWN':(0, 1), 'LEFT':(-1, 0), 'RIGHT':(1,0)}
board = None
players = None

def minimax(depth, maximizingPlayer, player1, player2, alpha, beta):
    if depth == 0:
        return voronaoi(player1), None

    if maximizingPlayer:  
        best = MIN 
        temp = list(moves.items())
        best_move = temp[0][0]
        for key, pos in temp:
            next_pos = player1.pos[0] + pos[0], player1.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                player1.update(next_pos[0], next_pos[1])
                val = minimax(depth - 1, False, player1, player2, alpha, beta)  
                if val[0] > best:
                    best = val[0]
                    best_move = pos
                player1.undo_move()
            alpha = max(alpha, best)  
            # Alpha Beta Pruning  
            if beta <= alpha:  
                break
        return best, best_move
    else: 
        best = MAX 
        temp = list(moves.items())
        best_move = temp[0][0]
        for key, pos in temp:
            next_pos = player2.pos[0] + pos[0], player2.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                player2.update(next_pos[0], next_pos[1])
                val = minimax(depth - 1, True, player1, player2, alpha, beta)  
                if val[0] < best:
                    best = val[0]
                    best_move = pos
                player2.undo_move()
            beta = min(beta, best)  
            # Alpha Beta Pruning  
            if beta <= alpha:  
                break 
        return best, best_move

class Player:
    def __init__(self, id):
        self.id = id
        self.pos = None
        self.last_pos = list()
'''
    def move(self):
        temp = list(moves.items()); random.shuffle(temp)
        for key, pos in temp:
            next_pos = self.pos[0] + pos[0], self.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                self.update(next_pos[0], next_pos[1])
                print(key)
                break
        self.pos = next_pos
'''
    def move(self):
        rivals = [player for player in players if not player.id == self.id]
        #for rival in rivals:
        result, next_move_key = minimax(5, 1, self, rival[0], alpha, beta)
        pos = moves[next_move_key]
        next_pos = self.pos[0] + pos[0], self.pos[1] + pos[1]
        self.update(next_pos[0], next_pos[1])
        print(next_move_key)



    def update(self, x, y):
        self.last_pos.append(pos)
        self.pos = x, y
        board.fill_cell(self.id, x, y)

    def undo_move(self):
        board.clear_cell(sel.pos[0], self.pos[1])
        self.pos = self.last_pos.pop()
    
class Board:
    def __init__(self, n):
        self.grid = [[-1 for i in range(30)] for j in range(20)]
        self.n_players = n
        self.voronaoi_grid = [[-1 for i in range(30)] for j in range(20)]
        self.scores = [0]*n

    def fill_cell(self, player, i, j):
        self.grid[j][i] = player
        scores[player] += 1

    def clear_cell(self, i, j):
        self.grid[j][i] = -1
        scores[player] -= 1

    def is_free(self, i, j):
        debug(f'is_free| i:{i} j:{j}')
        if 0 <= i < 30 and 0 <= j < 20:  
            return self.grid[j][i] == -1
        return False

    def print(self):
        for x, col in enumerate(self.grid):
            for y, val in enumerate(col):
                if val != -1:
                    debug(f'|{val}', end='')
                else:
                    debug(f'|F', end='')
            debug('\n')

    def voronaoi(self, player):
        self.voronaoi_grid.clear()
        self.voronaoi_grid = deepcopy(self.grid)
        v_scores = self.scores.copy()
        for x, col in enumerate(self.voronaoi_grid):
            for y, val in enumerate(col):
                if val == -1:
                    result = min([(abs(x-player.pos[0]) + abs(y-player.pos[1]), player.id) for player in players], key=lambds x: x[0])
                    self.voronaoi_grid[x][y] = result[1]
                    v_scores[result[1]] += 1
        return v_scores[player]

# game loop
while True:
    # n: total number of players (2 to 4).
    # p: your player number (0 to 3).
    n, p = [int(i) for i in input().split()]
    if not board:
        board = Board(n)
    if not players:
        players = [Player(i) for i in range(n)]
    for i in range(n):
        # x0: starting X coordinate of lightcycle (or -1)
        # y0: starting Y coordinate of lightcycle (or -1)
        # x1: starting X coordinate of lightcycle (can be the same as X0 if you play before this player)
        # y1: starting Y coordinate of lightcycle (can be the same as Y0 if you play before this player)
        x0, y0, x1, y1 = [int(j) for j in input().split()]
        debug(f'{i}: Initial {x0} {y0} | Final {x1} {y1}')
        players[i].update(x1,y1)    
    # A single line with UP, DOWN, LEFT or RIGHT
    # board.print()
    players[p].move()