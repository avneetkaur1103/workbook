import sys
import math
import random

def debug(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)

moves = {'UP':(0, -1), 'DOWN':(0, 1), 'LEFT':(-1, 0), 'RIGHT':(1,0)}
board = None
players = None

class Player:
    def __init__(self, id):
        self.id = id
        self.pos = None

    def move(self):
        temp = list(moves.items()); random.shuffle(temp)
        for key, pos in temp:
            next_pos = self.pos[0] + pos[0], self.pos[1] + pos[1]
            if board.is_free(next_pos[0], next_pos[1]):
                self.update(next_pos[0], next_pos[1])
                print(key)
                break
        self.pos = next_pos

    def update(self, x, y):
        self.pos = x, y
        board.fill(self.id, x, y)
    
class Board:
    def __init__(self, n):
        self.grid = [[-1 for i in range(30)] for j in range(20)]
        self.no_of_players = n

    def fill(self, player, i, j):
        self.grid[j][i] = player

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