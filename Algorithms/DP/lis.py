""" The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that
all elements of the subsequence are sorted in increasing order. """

def lis(arr):
	n = len(arr)
	_lis = [1] * n

	for i in range(1, n):
		for j in range(0, i):
			if arr[i] > arr[j] and _lis[i] < 1 + _lis[j]:
				_lis[i] = 1 + _lis[j]

	return max(_lis)

if __name__ == '__main__':
	arr = [10, 22, 9, 33, 21, 50, 41, 60] 
	print('LIS: ', lis(arr))
