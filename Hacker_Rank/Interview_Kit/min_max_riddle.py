#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the riddle function below.
def riddle(arr):
    # complete this function
    n = len(arr)
    windows = [[] for _ in range(n)]
    for i in range(n):
        ws = n-i
        _min = arr[i]
        for j in range(0, ws):
            if arr[i+j] < _min:
                _min = arr[i+j]
            windows[j].append(_min)
    for w in windows:
        print(w)
    return [max(w) for w in windows]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = riddle(arr)

    fptr.write(' '.join(map(str, res)))
    fptr.write('\n')

    fptr.close()
