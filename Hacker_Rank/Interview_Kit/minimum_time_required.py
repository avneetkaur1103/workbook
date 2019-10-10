#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minTime function below.
def get_items(machines, n):
    item = 0
    for m in machines:
        item += n//m
    return item

def minTime(machines, goal):
    machines.sort()
    ld = goal*machines[0]//len(machines) # if all machine works at rate machine[0]
    hd = goal*machines[-1]//len(machines)
    print(f'ld:{ld} hd:{hd}')
    while ld < hd:
        mid = (hd+ld)//2
        n_items = get_items(machines, mid)
        print(f'd:{mid} n_items:{n_items}')
        if n_items >= goal:
            hd = mid
        else:
            ld = mid+1
    return ld
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nGoal = input().split()

    n = int(nGoal[0])

    goal = int(nGoal[1])

    machines = list(map(int, input().rstrip().split()))

    ans = minTime(machines, goal)

    fptr.write(str(ans) + '\n')

    fptr.close()
