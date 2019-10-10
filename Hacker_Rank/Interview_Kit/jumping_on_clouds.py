#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
	n = len(c)
	dp = [float('inf')]*n
	dp[0] = 0
	dp[1] = 1
	for i in range(2, n):
		x = dp[i-1] + 1 if not c[i-1] else dp[i]
		y = dp[i-2] + 1 if not c[i-2] else dp[i]
		dp[i] = min(x, y)
	return dp[n-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
