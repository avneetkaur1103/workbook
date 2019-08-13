""" Radix sort """
from copy import deepcopy
def count_sort(arr, exp):
	count = [0] * 10
	output = [None] * len(arr)
	l = lambda x: (x//exp)%10 

	for val in map(l, arr):
		count[val] += 1

	for i in range(1, len(count)):
		count[i] += count[i-1]

	for i, val in reversed(list(enumerate(map(l, arr)))):
		output[count[val]-1] = arr[i]
		count[val] -= 1

	for i in range(len(output)):
		arr[i] = output[i]

def radix_sort(arr):
	max_ = max(arr)
	exp = 1

	while max_//exp:
		count_sort(arr, exp)
		exp = exp*10


arr = [12, 11, 13, 5, 6] 
# insertion_sort(arr)
radix_sort(arr)
print('Sorted Array: ', arr)