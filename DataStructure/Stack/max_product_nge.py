'''
	Given an array a[1..N]. For each element at position i (1 <= i <= N). Where

	L(i) is defined as closest index j such that j < i and a[j] > a[i]. If no such j exists then L(i) = 0.
	R(i) is defined as closest index k such that k > i and a[k] > a[i]. If no such k exists then R(i) = 0.
	LRProduct(i) = L(i)*R(i) .

	We need to find an index with maximum LRProduct
'''
def max_product(arr):
