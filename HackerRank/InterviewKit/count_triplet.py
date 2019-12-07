#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict
# Complete the countTriplets function below.
def countTriplets(arr, r):
	n = len(arr)
	d = defaultdict(list)
	result = 0
	for i in range(n):
		d[arr[i]].append(i)

	for i in range(1,n):
		mid = arr[i]
		c_prev = c_next = 0
		if r == 1:
			result += len(d[mid]) - 2 if len(d[mid]) - 2 > 0 else 0
			continue
		if mid*r in d:
			c_next = sum(1 for j in d[mid*r] if j > i )
		if mid//r in d:
			c_prev = sum(1 for j in d[mid//r] if j < i )
		result += c_prev*c_next
		
	return result


if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nr = input().rstrip().split()

	n = int(nr[0])

	r = int(nr[1])

	arr = list(map(int, input().rstrip().split()))

	ans = countTriplets(arr, r)
	print(ans)
	#fptr.write(str(ans) + '\n')

	#fptr.close()
