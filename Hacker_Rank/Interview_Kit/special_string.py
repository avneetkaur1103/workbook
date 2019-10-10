#!/bin/python3

import math
import os
import random
import re
import sys

def substrCount(n, s):
	count = 0
	dp = [[False for _ in range(n)] for _ in range(n)]
	for l in range(1, n+1):
		print(f'l:{l} count:{count}')
		for i in range(0, n-l+1):
			j = i+l-1
			if l == 1:
				dp[i][j] = True
				count += 1
			elif l == 2 and s[i] == s[j]:
				dp[i][j] = True
				count += 1
			elif l == 3 and s[i] == s[j] and dp[i+1][j-1]:
				dp[i][j] = True
				count += 1
			elif s[i] == s[j] and dp[i+1][j-1] and s[i] == s[i+1]:
				dp[i][j] = True
				count += 1
	for r in dp:
		for val in r:
			print(val, end=' ')
		print('\n')
	return count

if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	s = input()

	result = substrCount(n, s)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
