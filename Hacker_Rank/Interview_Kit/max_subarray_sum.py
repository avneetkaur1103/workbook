#https://www.hackerrank.com/challenges/maximum-subarray-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search

import math
import os
import random
import re
import sys
from bisect import bisect_right, insort
# Complete the maximumSum function below.
def maximumSum(a, m):
    n = len(a)
    prefix = a[:]
    max_sum = float('-inf')

    for i in range(1, n):
        prefix[i] += prefix[i-1]
    prefix = list(map(lambda x: x%m, prefix))
    #print(f'prefix: {prefix}')

    max_sum = max(prefix)
    sprefix = [prefix[0]]
    for i in range(1, n):
        partition = bisect_right(sprefix, prefix[i])
        if partition != len(sprefix):
            max_sum = max(max_sum, (prefix[i]-sprefix[partition] + m)%m)
        insort(sprefix, prefix[i])
    return max_sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nm = input().split()

        n = int(nm[0])

        m = int(nm[1])

        a = list(map(int, input().rstrip().split()))

        result = maximumSum(a, m)

        fptr.write(str(result) + '\n')

    fptr.close()
