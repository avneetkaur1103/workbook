""" There are N stations on route of a train. The train goes from station 0 to N-1.
 The ticket cost for all pair of stations (i, j) is given where j is greater than i. Find the minimum cost to reach the destination. """
INF = float('inf')

def min_cost(cost):
	n = len(cost)
	dp = [INF for _ in range(n)]

	dp[0] = 0
	for i in range(1, n):  # considering i as last node
		for j in range(i):
			dp[i] = min(dp[i], dp[j]+cost[j][i])

	return dp[-1]

if __name__ == '__main__':

	cost= [ [0, 15, 80, 90], 
	        [INF, 0, 40, 50], 
	        [INF, INF, 0, 70], 
	        [INF, INF, INF, 0]]
	print('Min cost:', min_cost(cost))