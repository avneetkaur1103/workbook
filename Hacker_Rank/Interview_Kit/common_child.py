#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the commonChild function below.
def commonChild(s1, s2):
	m = len(s2); n = len(s1)
	idx = count = 0
	while idx < n and idx < m:
		if not s1[idx] == s2[idx]:
			break
		idx += 1
	s1 = s1[idx:]
	s2 = s2[idx:]
	count += idx

	idx = 0
	m = len(s2); n = len(s1)
	while n-idx-1 >= 0 and m-idx-1 >=0:
		if not s1[n-idx-1] == s2[m-idx-1]:
			break
		idx += 1
	s1 = s1[:n-idx]
	s2 = s2[:n-idx]
	count += abs(idx)

	m = len(s2); n = len(s1)
	dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
	for i in range(1, n+1):
		for j in range(1, m+1):
			if s1[i-1] == s2[j-1]:
				dp[i][j] = 1 + dp[i-1][j-1]
			else:
				dp[i][j] = max(dp[i-1][j],dp[i][j-1])

	return dp[n][m] + count


if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	s1 = input()

	s2 = input()

	result = commonChild(s1, s2)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
