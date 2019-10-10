#!/bin/python3

import math
import os
import random
import re
import sys
from queue import Queue

# Complete the poisonousPlants function below.
def poisonousPlants(p):
	q1 = p[:]
	q2 = list()
	_max_d = 0

	while True:
		d =0
		for v in q1:
			if v < 0:
				continue
			elif not q2:
				q2.append(v)
			elif abs(q2[-1]) < v:
				d += 1
				q2.append(-v)
			else:
				q2.append(v)
		if not d:
			break
		else:
			_max_d += 1
			q1, q2 = q2, list()

	return _max_d


if __name__ == '__main__':
	#fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	p = list(map(int, input().rstrip().split()))

	result = poisonousPlants(p)
	print(result)
	#fptr.write(str(result) + '\n')

	#fptr.close()
