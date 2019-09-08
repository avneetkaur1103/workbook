import sys
import math
from collections import namedtuple
from queue import Queue

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
def debug(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)

width, height, my_id = [int(i) for i in input().split()]
debug(f'width: {width} height: {height} my_id:{my_id}')

grid = [[-1 for _ in range(width)] for _ in range(height)]
items = [[0 for _ in range(width)] for _ in range(height)]
positions = [None, None]
n_bombs = 0
ranges = [None] * 4
Cell = namedtuple('Cell', 'val own time range')
class DPCell:
    def __init__(self, val, dist, visited, min_bombing_duration):
        self.val = val
        self.dist = dist
        self.visited = visited
        self.min_bombing_duration = min_bombing_duration

    def __iter__(self):
        return iter([self.val, self.dist, self.visited, self.min_bombing_duration])

class GameSimulation:
    def __init__(self):
        self.best_positions_bombs = None
        self.best_positions_points = None
        self.last_pos = None
        self.safe_positions = None
        self.dp = None # Simulation grid

    @staticmethod
    def add_reacability(dp, pos):
        i, j = pos
        dp[i][j].dist, dp[i][j].visited = 0, True
        q = Queue()
        neighbours = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        q.put((dp[i][j], (i, j)))

        while q.qsize():
            (_, dist, _, _), (i, j) = q.get()
            for di, dj in neighbours:
                if 0 <= i+di < height and 0 <= j+dj < width and not dp[i+di][j+dj].visited and dp[i+di][j+dj].min_bombing_duration == sys.maxsize and (grid[i+di][j+dj].val == -1 # Empty\
                 or (grid[i+di][j+dj].val > 0 and items[i+di][j+dj] > 0)) :
                    dp[i+di][j+dj].dist, dp[i+di][j+dj].visited = dist + 1, True
                    q.put((dp[i+di][j+dj], (i+di, j+dj)))

    def init_board(self, pos):
        self.dp.clear()
        dp = self.dp
        dp = [[DPCell(0, sys.maxsize, False, sys.maxsize) for _ in range(width)] for _ in range(height)]
        for i in range(len(grid)):  # if bomb placed here
            for j in range(len(grid[0])):
                if grid[i][j].val >= 0:
                    _range = ranges[my_id]
                    for x in range(max(i-(_range-1), 0), min(i+(_range-1), height)):
                        if grid[x][j].val == -2:
                            break
                        if grid[x][j].val == -1:
                                dp[x][j].val += 1
                    for y in range(max(j-(_range-1), 0), min(j+(_range-1), width)):
                        if grid[i][y].val == -2:
                            break
                        if grid[i][y].val == -1:
                                dp[i][y].val += 1

    def add_bombs(self, pos):
        dp = self.dp
        for i in range(len(grid)):
            for j in range(len(grid[0])):                       
                if grid[i][j].val == 3:  # if alreday a bomb here
                _range = grid[i][j].time
                    for x in range(max(i-(_range-1), 0), min(i+(_range-1), height)):
                        if grid[x][j].val == -1:
                                dp[x][j].val = 0
                                dp[x][j].min_bombing_duration = min(dp[x][j].min_bombing_duration, grid[i][j].time)
                    for y in range(max(j-(_range-1), 0), min(j+(_range-1), width)):
                        if grid[i][y].val == -1:
                                dp[i][y].val = 0
                                dp[i][y].min_bombing_duration = min(dp[i][y].min_bombing_duration, grid[i][j].time)
        self.add_reacability(dp, pos)

    def evaluate_game(self, pos)
        dp = self.dp
        self.init_board(pos) # static without bombs
        self.add_bombs(pos)
        
        # debug(f'dp: {dp}')
        self.best_positions_bombs = sorted([(dp[i][j].val, -1*dp[i][j].dist, (i,j)) for j in range(len(dp[0])) for i in range(len(dp)) if not dp[i][j].min_bombing_duration == sys.maxsize or not dp[i][j].dist == sys.maxsize], key=lambda elem: (elem[0], elem[1]), reverse=True)
        debug(f'best_positions_bombs: {self.best_positions_bombs}')
        self.best_positions_points = sorted([(abs(pos[0] - i) + abs(pos[1] - j), (i, j)) for j in range(len(items[0])) for i in range(len(items)) if items[i][j] and dp[i][j].min_bombing_duration == sys.maxsize])
        debug(f'best_positions_points: {self.best_positions_points}')
        return dp

    def try_bomb_at(self, plant_bomb_at):
        i, j = plant_bomb_at
        temp = grid[i][j]
        grid[i][j] = Cell(3, my_id, 8, ranges[my_id]) # simulation 
        self.evaluate_bombs(self, plant_bomb_at)
        grid[i][j] = temp
        if not safe_positions:
            return None
        return plant_bomb_at

    def play(self, pos):
        bp = None
        while not bp:
            if n_bombs:
                while self.best_positions_bombs:
                    _, _, (x,y) = self.best_positions_bombs.pop(0)
                    bp = self.try_bomb_at((x,y))
                    if bp:
                        debug(f'bp:{bp} pos: {curr_pos}')
                        print(f"BOMB {bp[1]} {bp[0]}")
                        return
            if self.best_positions_points:
                _, bp = self.best_positions_points.pop(0)
            if self.safe_positions:
                bp = self.safe_positions.pop(0)
        if bp:
            debug(f'bp:{bp} pos: {curr_pos}')
            print(f'MOVE {bp[1]} {bp[0]}')
        return

gp = GamePlay()
bp = None
# game loop
while True:
    items = [[0 for _ in range(width)] for _ in range(height)]
    for i in range(height):
        row = input()
        debug(f'{row}')
        for col, val in enumerate(list(row)):
            if val == '.':
                grid[i][col] = Cell(-1, None, sys.maxsize, None)
            elif val == 'x' or val == 'X':
                grid[i][col] = Cell(-2, None, sys.maxsize, None)
            else:
                grid[i][col] = Cell(int(i), None, sys.maxsize, None)

    entities = int(input())
    debug(f'entities: {entities}')
    for i in range(entities):
        entity_type, owner, x, y, param_1, param_2 = [int(j) for j in input().split()]
        debug(f'entity_type:{entity_type}, owner:{owner}, x:{x}, y:{y}, param_1:{param_1}, param_2:{param_2}')
        if entity_type == 0:  # Player
            positions[owner] = y, x
            if owner == my_id:
                n_bombs = param_1
                ranges[my_id] = param_2
        elif entity_type == 1:
            time = param_1
            grid[y][x] = Cell(3, owner, param_1, param_2)  # Bomb
        else:  #items
            items[y][x] = param_1  # val 1 or 2 

    curr_pos = positions[my_id]
    gp.play(curr_pos)
