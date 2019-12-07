#!/bin/python3

import math
import os
import random
import re
import sys

def debug(*args, **kwargs):
	print(*args, **kwargs, file=sys.stderr)

def print_2D(dp):
	for i, x in enumerate(dp):
		for j, val in enumerate(x):
			print(val, end=' ')
		print('')
	print('-'*10)
# Complete the abbreviation function below.
def abbreviation(a, b):
	n, m = len(a), len(b)
	dp = [[False for _ in range(n+1)] for _ in range(m+1)]
	
	for i in range(n+1):
		dp[0][i] = True
	for i in range(1, m+1):
		for j in range(1, n+1):
			dp[i][j] = (dp[i-1][j-1] and a[j-1].upper() == b[i-1]) or (dp[i][j-1] if a[j-1].islower() else False)
			print(f'{i,j} {dp[i][j]} =>{dp[i-1][j-1]} and {a[j-1].upper()} == {b[i-1].upper()} or {dp[i][j-1]}')

	print_2D(dp)
	return dp[m][n]


if __name__ == '__main__':
	a = 'AfPZN'
	b = 'APZNC'
	
	print(f'result: {abbreviation(a,b)}')

	'''
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        a = input()

        b = input()

        result = abbreviation(a, b)

        fptr.write(result + '\n')

    fptr.close()'''
