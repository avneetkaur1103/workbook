""" Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. """
import sys
def partition(str):
	n = len(str)
	dp = [[sys.maxsize for _ in range(n)] for _ in range(n)]
	is_palindrome = [[False for _ in range(n)] for _ in range(n)]

	for l in range(1,n+1):
		for i in range(n-l+1):
			j = i + l -1
			if l == 1:
				is_palindrome[i][j] = True
				dp[i][j] = 0
			else:
				is_palindrome[i][j] = str[i] == str[j] if l == 2 else str[i] == str[j] and is_palindrome[i+1][j-1]
				if is_palindrome[i][j]:
					dp[i][j] = 0
				else:
					for k in range(i,j):
						dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j])
	return dp[0][n-1]


if __name__ == '__main__':
	str = "ababbbabbababa"
	print(partition(str))