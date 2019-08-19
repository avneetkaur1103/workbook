""" Given a sequence of matrices, find the most efficient way to multiply these matrices together.
 The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications."""
import sys

def matrix_chain(p):
	n = len(p)
	dp = [[None for _ in range(n)] for _ in range(n)]

	for i in range(n):
		dp[i][i] = 0

	for l in range(2,n):
		for i in range(1, n-(l-1)):
			j = i + (l-1)
			dp[i][j] = sys.maxsize
			for k in range(i,j):
				temp = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]
				if temp < dp[i][j]:
					dp[i][j] = temp

	return dp[1][n-1]

if __name__ == '__main__':
	arr = [1, 2, 3, 4, 3]
	print('Ans: ', matrix_chain(arr))