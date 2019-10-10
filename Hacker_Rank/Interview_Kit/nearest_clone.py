#!/bin/python3

import math
import os
import random
import re
import sys
from queue import Queue
from collections import defaultdict
# Complete the findShortest function below.

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] to <name>_to[i].
#
#
def bfs(src, adj_list, colors, target):
    n = len(adj_list)
    visited = [False]*(n+1)
    q = Queue()
    q.put((src, 0))
    visited[src] = True

    while q.qsize():
        u, dist = q.get()
        for v in adj_list[u]:
            if not visited[v]:
                visited[v] = True
                if colors[v-1] == target:
                    return dist+1
                q.put((v,dist+1))
    return -1


def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    # solve here
    adj_list = defaultdict(list)
    for i, j in zip(graph_from, graph_to):
        adj_list[i].append(j)
        adj_list[j].append(i)

    min_d = float('inf')
    for i, color in enumerate(ids):
        if ids[i] == val:
            d = bfs(i+1, adj_list, ids, val)
            if not d == -1:
                min_d = min(d, min_d)
    min_d = min_d if not min_d == float('inf') else -1
    return min_d

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    graph_nodes, graph_edges = map(int, input().split())

    graph_from = [0] * graph_edges
    graph_to = [0] * graph_edges

    for i in range(graph_edges):
        graph_from[i], graph_to[i] = map(int, input().split())

    ids = list(map(int, input().rstrip().split()))

    val = int(input())

    ans = findShortest(graph_nodes, graph_from, graph_to, ids, val)

    fptr.write(str(ans) + '\n')

    fptr.close()
