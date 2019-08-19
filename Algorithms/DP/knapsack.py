""" 0-1 Knapsack problem """

def max_ks(weights, values, W):
	n = len(weights)
	dp = [[0 for _ in range(n+1)] for _ in range(W+1)]

	for i in range(W+1):
		for j in range(n+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			else:
				x = (dp[i-weights[j-1]][j-1] + values[j-1]) if i >= weights[j-1] else 0
				y = dp[i][j-1] if j > 0 else 0
				dp[i][j] = max(x, y)
	return dp[W][n]

if __name__ == '__main__':
	val = [60, 100, 120] 
	wt = [10, 20, 30] 
	W = 50
	print('Max Knapsack: ', max_ks(wt, val, W))