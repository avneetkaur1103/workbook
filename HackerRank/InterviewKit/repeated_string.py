#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
	n_str = len(s)
	count = s.count('a')

	result = count*(n//n_str)
	result += s[:n%n_str].count('a') if n%n_str else 0
	return result

if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	s = input()

	n = int(input())

	result = repeatedString(s, n)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
