#!/bin/python3

import math
import os
import random
import re
import sys
def union(parent, x, y):
	px, x_has_machine = find(parent, x)
	py, y_has_machine = find(parent, y)
	if x_has_machine and y_has_machine:
		return False

	parent[py] = px, y_has_machine
	parent[px] = -1, x_has_machine or y_has_machine
	return True

def find(parent, x):
	while not parent[x][0] == -1:
		x = parent[x][0]
	return x, parent[x][1]

# Complete the minTime function below.
def minTime(n, roads, machines):
	cost = 0
	parent = [(-1, False)]*n
	for machine in machines:
		parent[machine] = (-1, True)

	roads = sorted(roads, key=lambda e: e[2], reverse=True)
	for u, v, wt in roads:
		if not union(parent, u, v):
			cost += wt
	return cost


if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nk = input().split()

	n = int(nk[0])

	k = int(nk[1])

	roads = []

	for _ in range(n - 1):
		roads.append(list(map(int, input().rstrip().split())))

	machines = []

	for _ in range(k):
		machines_item = int(input())
		machines.append(machines_item)

	result = minTime(n, roads, machines)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
