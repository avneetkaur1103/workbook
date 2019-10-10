#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

# Complete the pairs function below.
def pairs(k, arr):
    d = defaultdict(int)
    for i in arr:
        d[i] += 1

    count = 0
    for i in arr:
        if d[k-i] > 0:
            d[k-i] -= 1
            count += 1
        elif d[i-k] > 0:
            d[i-k] -= 1
            count += 1

    return count

if __name__ == '__main__':
    result_path = os.path.join(os.getcwd(), 'result.txt')
    os.environ['OUTPUT_PATH'] = result_path
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    arr = list(map(int, input().rstrip().split()))

    result = pairs(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
