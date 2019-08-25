""" How to print maximum no of A's using 4 keys. 1.A 2.Ctrl-A 3.Ctrl-C 4.Ctrl-V """

def max_a(n):
	dp = [i for i in range(n)]

	if n > 6:
		for i in range(6, n):
			for j in range(i-3, 1, -1):
				dp[i] = dp[j] * i - j - 1

	return dp[-1]

if __name__ == '__main__':
	n = 7
	print(f"Max A's for {n} key strokes", max_a(n))
