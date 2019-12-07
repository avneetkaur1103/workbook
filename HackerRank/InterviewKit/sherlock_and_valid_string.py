#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isValid function below.
def isValid(s):
	frequency = [0]*26
	result = False
	for i in s:
		frequency[ord(i) - ord('a')] += 1
	frequency = [val for val in frequency if val > 0]
	_max = max(frequency)
	_min = min(frequency)
	_max_count = frequency.count(_max)
	_min_count = frequency.count(_min)
	print(f'_max: {_max} _min:{_min} _max_c: {_max_count} _min_c:{_min_count}\nfreq:{frequency}')
	if _max == _min:
		return 'YES'
	if _min_count*_min + _max_count*_max == len(s) and ((_max == _min+1 and _max_count == 1) or _min_count == 1):
		return 'YES'
	else:
		return 'NO'

if __name__ == '__main__':
	# fptr = open(os.environ['OUTPUT_PATH'], 'w')

	s = input()

	result = isValid(s)
	print(result)
	# fptr.write(result + '\n')

	# fptr.close()
