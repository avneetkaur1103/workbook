#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the largestRectangle function below.
def largestRectangle(h):
    n = len(h)
    next_greater_f = [i for i in range(n)]
    stack = list()
    stack.append(0)
    for i in range(1, n):
        if not stack:
            stack.append(i)
        elif h[i] >= h[stack[-1]]:
            stack.append(i)
        else:
            while stack and h[stack[-1]] > h[i]:
                idx = stack.pop()
                next_greater_f[idx] = i
            stack.append(i)

    for v in stack:
        next_greater_f[v] = n
    print(f'Debug: next_greater_f:{next_greater_f}')

    stack.clear()
    next_greater_b = [i for i in range(n)]
    stack.append(n-1)
    for i in range(n-2, -1, -1):
        if not stack:
            stack.append(i)
        elif h[i] >= h[stack[-1]]:
            stack.append(i)
        else:
            while stack and h[stack[-1]] > h[i]:
                idx = stack.pop()
                next_greater_b[idx] = i
            stack.append(i)
    for v in stack:
        next_greater_b[v] = -1
    print(f'Debug: next_greater_b:{next_greater_b}')

    max_area = float('-inf')
    for i in range(n):
        area = (next_greater_f[i] - next_greater_b[i]-1)*h[i]
        max_area = max(area, max_area)

    return max_area



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    h = list(map(int, input().rstrip().split()))

    result = largestRectangle(h)

    fptr.write(str(result) + '\n')

    fptr.close()
