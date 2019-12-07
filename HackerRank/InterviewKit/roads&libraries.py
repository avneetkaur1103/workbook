#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

cost = 0
def dfs(src, adj_list, visited, c_road):
    global cost
    visited[src] = True
    for v in adj_list[src]:
        if not visited[v]:
            cost += c_road
            dfs(v, adj_list, visited, c_road)

# Complete the roadsAndLibraries function below.
def roadsAndLibraries(n, c_lib, c_road, cities):
    global cost
    cost = 0
    no_roads_cost = n*c_lib
    adj_list = defaultdict(list)
    for u, v in cities:
        adj_list[u].append(v)
        adj_list[v].append(u)

    visited = [False]*(n+1)
    for i in range(1, n+1):
        if not visited[i]:
            cost += c_lib
            dfs(i, adj_list, visited, c_road)

    return min(cost, no_roads_cost)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nmC_libC_road = input().split()

        n = int(nmC_libC_road[0])

        m = int(nmC_libC_road[1])

        c_lib = int(nmC_libC_road[2])

        c_road = int(nmC_libC_road[3])

        cities = []

        for _ in range(m):
            cities.append(list(map(int, input().rstrip().split())))

        result = roadsAndLibraries(n, c_lib, c_road, cities)

        fptr.write(str(result) + '\n')

    fptr.close()
