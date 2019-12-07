#!/bin/python3

import math
import os
import random
import re
import sys
from queue import Queue

moves = [(1,0),(-1,0),(0,1),(0,-1)]
# Complete the minimumMoves function below.
def minimumMoves(grid, startX, startY, goalX, goalY):
	q = Queue()
	n = len(grid)
	visited = [[False for _ in range(n)] for _ in range(n)]
	parent = [[(None, None) for _ in range(n)] for _ in range(n)]
	q.put((startX, startY))

	while q.qsize():
		x, y = q.get()
		visited[x][y] = True
		if x == goalX and y == goalY:
			break
		for dx, dy in moves:
			if 0 <= x+dx < n and 0 <= y+dy < n and not visited[x+dx][y+dy] and not grid[x+dx][y+dy] == 'X':
				q.put((x+dx,y+dy))
				parent[x+dx][y+dy] = (x,y)

	x = goalX; y = goalY
	ldx = 0; ldy = 0
	d = 0
	while not parent[x][y] == (None, None):
		px, py = parent[x][y]
		dx = abs(x - px) ; dy = abs(y - py)
		print(f'dx: {dx} dy: {dy}|ldx: {ldx} ldy: {ldy}|{ldx^dx + dy^ldy}')
		if (ldx^dx) + (dy^ldy):
			d += 1
		x, y = px, py
		ldx, ldy = dx, dy
		print(f'({x},{y}| {d})->')

	return d

if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	grid = []

	for _ in range(n):
		grid_item = input()
		grid.append(grid_item)

	startXStartY = input().split()

	startX = int(startXStartY[0])

	startY = int(startXStartY[1])

	goalX = int(startXStartY[2])

	goalY = int(startXStartY[3])

	result = minimumMoves(grid, startX, startY, goalX, goalY)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
