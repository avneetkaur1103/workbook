#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
	stack = list()
	types = {'{':'}', '(':')', '[':']'}
	for v in s:
		if v in types:
			stack.append(v)
		else:
			if stack and types[stack[-1]] == v:
				stack.pop()
			else:
				return 'NO'
	return 'YES' if not stack else 'NO'

if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	t = int(input())

	for t_itr in range(t):
		s = input()

		result = isBalanced(s)
		print(result)
		#fptr.write(result + '\n')

	#fptr.close()
