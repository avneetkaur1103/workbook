""" C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1"""

def bcoeff(n,k):
	dp = [[0 for _ in range(k+1)] for _ in range(n+1)]

	for i in range(1, n+1):
		for j in range(min(i, k)+1):
			if j == 0 or j == i:
				dp[i][j] = 1
			else:
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

	return dp[n][k]

if __name__ == '__main__':
	n = 5; k = 2
	print(f'{n}C{k}', bcoeff(n,k))
