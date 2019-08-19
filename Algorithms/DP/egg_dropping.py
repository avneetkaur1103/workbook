""" Egg dropping puzzle """
import sys

def egg_dropping(n, k): #n eggs k floors
	dp = [[sys.maxsize for _ in range(n+1)] for _ in range(k+1)]

	for i in range(k+1):
		for j in range(n+1):
			if i == 0:
				dp[i][j] = 0
			elif j == 1:
				dp[i][j] = i
			else:
				for k in range(1,i+1):
					dp[i][j] = min(dp[i][j], 1+ max(dp[k-1][j-1], dp[i-k][j]))

	return dp[k][n]

if __name__ == '__main__':
	print('Min Egg dropping:', egg_dropping(2, 36))