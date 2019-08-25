""" A number can always be represented as a sum of squares of other numbers.
Note that 1 is a square and we can always break a number as (1*1 + 1*1 + 1*1 + …). Given a number n, find the minimum number of squares that sum to X. """
import math

def min_square_sum(no):
	dp = [i for i in range(no+1)]
	for i in range(4, no+1):
		for j in range(math.floor(math.sqrt(i)), 0, -1):
			dp[i] = min(dp[i], dp[i - j*j] + 1)
	return dp[no]

if __name__ == '__main__':
	print('Min square sum ', min_square_sum(6))




