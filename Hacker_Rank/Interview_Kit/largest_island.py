#!/bin/python3

import math
import os
import random
import re
import sys

neighbours = [(-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]
def dfs(grid, i, j, n ,m, visited):
    l = 1
    visited[i][j] = True
    for di, dj in neighbours:
        if 0 <= i + di < n and 0 <= j + dj < m and not visited[i+di][j+dj] and grid[i+di][j+dj]:
            l += dfs(grid, i+di, j+dj, n, m, visited)
    return l

# Complete the maxRegion function below.
def maxRegion(grid):
    n = len(grid)
    m = len(grid[0])

    visited = [[False for _ in range(m)] for _ in range(n)]
    max_l = float('-inf')
    for i in range(n):
        for j in range(m):
            if grid[i][j] and not visited[i][j]:
                l = dfs(grid, i, j, n, m, visited)
                print(f'l:{l}')
                max_l = max(max_l, l)
    return max_l

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    m = int(input())

    grid = []

    for _ in range(n):
        grid.append(list(map(int, input().rstrip().split())))

    res = maxRegion(grid)

    fptr.write(str(res) + '\n')

    fptr.close()
