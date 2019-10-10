#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the activityNotifications function below.
import heapq

max_heap = []
min_heap = []

def median(_add=None, _remove=None):
	result = None
	max_l = len(max_heap)
	min_l = len(min_heap)

	if _add:
		if not min_l:
			heapq.heappush(min_heap, _add)

		elif max_l > min_l:
			if _add < max_heap[0]:
				temp = max_heap[0]
				heapq._heapreplace_max(max_heap, _add)
				heapq.heappush(min_heap,temp)
			else:
				heapq.heappush(min_heap, _add)

		elif max_l < min_l:
			if _add > min_heap[0]:
				temp = min_heap[0]
				heapq.heapreplace(min_heap, _add)
				max_heap.append(temp)
				heapq._siftdown_max(max_heap, 0, max_l)
			else:
				max_heap.append(_add)
				heapq._siftdown_max(max_heap, 0, max_l)

		else:
			if _add > min_heap[0]:
				heapq.heappush(min_heap, _add)
			else:
				max_heap.append(_add)
				heapq._siftdown_max(max_heap, 0, max_l)

	max_l = len(max_heap)
	min_l = len(min_heap)
	if _remove:
		if min_heap and _remove >= min_heap[0]:
			indx = min_heap.index(_remove)
			min_heap[indx] = min_heap[-1]
			min_heap.pop()
			if indx < len(min_heap):
				heapq._siftup(min_heap, indx)
				heapq._siftdown(min_heap, 0, indx)

		elif max_heap and _remove <= max_heap[0]:
			indx = max_heap.index(_remove)
			max_heap[indx] = max_heap[-1]
			max_heap.pop()
			if indx < len(max_heap):
				heapq._siftup_max(max_heap, indx)
				heapq._siftdown_max(max_heap, 0, indx)

		max_l = len(max_heap)
		min_l = len(min_heap)

		if max_l - min_l >= 2:
			temp = max_heap[0]
			heapq._heappop_max(max_heap)
			heapq.heappush(min_heap, temp)

		elif min_l - max_l >= 2:
			temp = min_heap[0]
			heapq.heappop(min_heap)
			max_heap.append(temp)
			heapq._siftdown_max(max_heap, 0, max_l)

	min_l = len(min_heap)
	max_l = len(max_heap)
	if min_l == max_l:
		result = (max_heap[0] + min_heap[0]) / 2
	# print(f'debug: max_heap[0]: {max_heap[0]} min_heap[0]:{min_heap[0]}')
	elif min_l > max_l:
		result = min_heap[0]
	else:
		result = max_heap[0]
	return result

def activityNotifications(expenditure, d):
	q = list()
	n = len(expenditure)
	if n <= d:
		return 0

	count = 0
	for i in range(n):
		if i < d:
			q.append(expenditure[i])
			median(_add=expenditure[i])
		else:
			mid = median()
			print(f'median: {mid}\n exp:{expenditure[i]}\nmin_heap: {len(min_heap)}|{min_heap}\nmax_heap:{len(max_heap)}|{max_heap}')
			if expenditure[i] >= 2 * mid:
				count += 1
				print(f'count: {count}')
			median(_add=expenditure[i], _remove=q[0])
			q.pop(0)
			q.append(expenditure[i])
	return count

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
