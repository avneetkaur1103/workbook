""" Given two strings str1 and str2 and below operations that can performed on str1.
 Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’. """

def distance(str1, str2):
	n = len(str1) ; m = len(str2)
	dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
	for i in range(n+1):
		for j in range(m+1):
			if j == 0:
				dp[i][j] = i
			elif i == 0:
				dp[i][j] = j
			elif str1[i-1] == str2[j-1]: #optimal decision making
				dp[i][j] = dp[i-1][j-1]
			else:
				dp[i][j] = 1 + min(dp[i-1][j],  # deleted in str1
								dp[i][j-1],     # inserted in str1
								dp[i-1][j-1])   # replaced
	return dp[n][m]

if __name__ == '__main__':
	str1 = "sunday"
	str2 = "saturday"
	print(distance(str1, str2))