#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

dbmax = 30000
digimax = 20
dp = [[0 for _ in range(digimax)] for _ in range(dbmax)]
c = [0] * dbmax
# Complete the decibinaryNumbers function below.
def dbvalues(x):
    i = 0
    result = 0
    while x:
        result += (x % 10) * pow(2, i)
        x = x//10
        i += 1
    return result

def precompute():
    for dbval in range(dbmax):
        dp[dbval][0] = 1 if dbval < 10 else 0
        for digit in range(1, digimax):
            for i in range(10):
                val = dbval - i * (1<<digit)
                if val < 0:
                    break
                dp[dbval][digit] += dp[val][digit-1]
    for dbval in range(1, dbmax):
        c[dbval] = dp[dbval-1][-1] + c[dbval-1]
    #print(f'DP: {dp[:digimax]}')
    #print(f'c: {c[:digimax]}')

def decibinaryNumbers(x):
    result = 0
    indx, val = next((i, val) for i, val in enumerate(c) if val > x-1)
    offset = x-1 - c[indx-1]
    value = indx-1

    for digit in range(digimax, 0, -1):
        for i in range(10):
            val = value - i * (1<<digit)
            if val < 0:
                break
            if offset < dp[val][digit-1]:
                result += i
                value -= i * (1<<digit)
                break
            offset -= dp[val][digit-1]
        result *= 10
    result += value

    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())
    precompute()
    for q_itr in range(q):
        x = int(input())

        result = decibinaryNumbers(x)

        fptr.write(str(result) + '\n')

    fptr.close()
