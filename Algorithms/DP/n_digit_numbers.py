""" A number is non-decreasing if every digit (except the first one) is greater than or equal to previous digit. For example, 223, 4455567, 899, are non-decreasing numbers.
So, given the number of digits n, you are required to find the count of total non-decreasing numbers with n digits."""

def count_numbers(n):
	dp = [[0 for _ in range(n)] for _ in range(10)]

	for l in range(1, n+1):
		for d in range(10):
			if l == 1:
				dp[d][l-1] = 1
			else:
				for i in range(d, 10):
					dp[d][l-1] += dp[i][l-2]
	return sum(dp[i][n-1] for i in range(10))

if __name__ == '__main__':
	print('Total non-decreasing no of len {} is {}'.format(3, count_numbers(3)))