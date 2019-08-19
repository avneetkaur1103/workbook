""" Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same. """

def is_subset_sum(arr, sum):
	n = len(arr)
	dp = [[False for _ in range(n+1)] for _ in range(sum+1)]

	for i in range(sum+1):
		for j in range(n+1):
			if i == 0:
				dp[i][j] = True
			elif j == 0:
				dp[i][j] = False
			else:
				x = dp[i-arr[j-1]][j-1] if i >= arr[j-1] else False
				y = dp[i][j-1]
				dp[i][j] = x or y
	return dp[sum][n]

if __name__ == '__main__':
	arr = [3, 1, 1, 2, 2, 3]
	_sum = sum(arr)
	result = is_subset_sum(arr,_sum//2) if not _sum & 1 else False
	print('Is subset sum: ', result)
