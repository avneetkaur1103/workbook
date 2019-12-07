#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the activityNotifications function below.
count = [0]*201
def get_median():
	temp = count[:]
	for i in range(1,201):
		temp[i] += temp[i-1]

	mid = 0
	if d&1:
		a = d//2
		for i in range(201):
			if temp[i]>=a:
				a = i
		mid = a
	else:
		a = d//2
		b = a+1
		for i in range(201):
			if temp[i]>=a:
				a = i
		for i in range(a, 201):
			if temp[i] >= b:
				b = i
		mid = (a+b)/2

	return mid

def activityNotifications(expenditure, d):
	q = list()
	n = len(expenditure)
	if n <= d:
		return 0

	alerts = 0
	for i in range(n):
		if i < d:
			count[expenditure[i]] += 1
		else:
			mid = get_median()
			if expenditure[i] >= 2 * mid:
				alerts += 1
			count[expenditure[i]] += 1
			count[expenditure[i-d]] -= 1
	return alerts

if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	nd = input().split()

	n = int(nd[0])

	d = int(nd[1])

	expenditure = list(map(int, input().rstrip().split()))

	result = activityNotifications(expenditure, d)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
