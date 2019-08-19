""" Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to reach the end of the array"""
import sys

def min_jumps(arr):
	n = len(arr)
	dp = [sys.maxsize for _ in range(n)]

	for i in range(n-1, -1, -1):
		if i == n-1:
			dp[i] = 0
		else:
			jumps = arr[i]
			if jumps:
				for k in range(1, jumps+1):
					if k + i < n:
						dp[i] = min(dp[i], dp[i+k]+1)

	return dp[0]

if __name__ == '__main__':
	arr = [1, 3, 6, 1, 0, 9] 
	print('Min Jumps: ', min_jumps(arr))