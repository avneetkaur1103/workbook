#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubsetSum function below.
def maxSubsetSum(arr):
	n = len(arr)
	if n < 3:
		return max(arr)

	max_so_far = arr[:2]
	max_so_far[1] = max(max_so_far[1], max_so_far[0])
	result = max(max_so_far)
	for i in range(2,n):
		max_so_far[0], max_so_far[1] = max_so_far[1], max(arr[i], max_so_far[1], arr[i]+max_so_far[0])
		if max_so_far[1] > result:
			result = max_so_far[1]

	return result


if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	arr = list(map(int, input().rstrip().split()))

	res = maxSubsetSum(arr)
	print(res)
	#fptr.write(str(res) + '\n')

	#fptr.close()
