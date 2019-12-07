#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the triplets function below.
def triplets(a, b, c):
    a = sorted(set(a))
    b = sorted(set(b))
    c = sorted(set(c))

    ans = 0
    last_ai, last_ci = 0, 0
    for bi in range(len(b)):
        ai = last_ai
        while ai < len(a) and a[ai] <= b[bi]:
            ai += 1
        ci = last_ci
        while ci < len(c) and c[ci] <= b[bi]:
            ci += 1
        ans += ai * ci
        last_ai, last_ci = ai, ci
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    lenaLenbLenc = input().split()

    lena = int(lenaLenbLenc[0])

    lenb = int(lenaLenbLenc[1])

    lenc = int(lenaLenbLenc[2])

    arra = list(map(int, input().rstrip().split()))

    arrb = list(map(int, input().rstrip().split()))

    arrc = list(map(int, input().rstrip().split()))

    ans = triplets(arra, arrb, arrc)

    fptr.write(str(ans) + '\n')

    fptr.close()
