""" Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
 how many ways can we make the change? The order of coins doesn’t matter."""

def coin_change(coins, n):
	m = len(coins)
	dp = [[0 for _ in range(m)] for _ in range(n+1)]

	for i in range(m):
		dp[0][i] = 1

	for i in range(1, n+1):
		for j in range(m):
			x = dp[i-arr[j]][j] if i >= coins[j] else 0  # inclusive
			y = dp[i][j-1] if j > 0 else 0  # exclusive
			dp[i][j] = x + y

	return dp[n][m-1]

if __name__ == '__main__':
	arr = [1, 2, 3] 
	print('Total combination: ',coin_change(arr, 4))