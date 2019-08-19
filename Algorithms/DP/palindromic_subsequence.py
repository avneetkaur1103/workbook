""" Given a sequence, find the length of the longest palindromic subsequence in it. """

def lps(str):
	n = len(str)
	dp = [[0 for _ in range(n)] for _ in range(n)]

	for l in range(1, n+1):
		for i in range(n-(l-1)):
			j = i+l-1
			if l == 1:
				dp[i][j] = 1
			elif l == 2:
				dp[i][j] = 2 if str[i] == str[j] else max(dp[i+1][j], dp[i][j-1])
			else:
				dp[i][j] = (dp[i+1][j-1] + 2) if str[i] == str[j] else max(dp[i+1][j], dp[i][j-1])
				# print(f'Debug:l={l}||i:{i}/j:{j}: {str[i:j+1]} => val:{dp[i][j]}')
	return dp[0][n-1]

if __name__ == '__main__':
	seq = "GEEKSFORGEEKS"
	print('LPS: ', lps(seq))