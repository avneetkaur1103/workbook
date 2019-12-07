#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

# Complete the freqQuery function below.
def freqQuery(queries):
    d = defaultdict(int)
    freq = defaultdict(int)
    result = list()
    for q, val in queries:
        if q == 1:
            if d[val]:
                freq[d[val]] -= 1
            d[val] += 1
            freq[d[val]] += 1

        elif q == 2:
            if d[val]:
                freq[d[val]] -= 1
                d[val] -= 1
                freq[d[val]] += 1
        else:
            if freq[val]:
                result.append(1)
            else:
                result.append(0)
    return result

if __name__ == '__main__':
	result_path = os.path.join(os.getcwd(), 'result.txt')
	os.environ['OUTPUT_PATH'] = result_path
	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	q = int(input().strip())

	queries = []

	for _ in range(q):
		queries.append(list(map(int, input().rstrip().split())))

	ans = freqQuery(queries)

	fptr.write('\n'.join(map(str, ans)))
	fptr.write('\n')

	fptr.close()
