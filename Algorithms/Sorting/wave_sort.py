""" Given an unsorted array of integers, sort the array into a wave like array.
An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= 
Idea: pick even places to be max of it's adjecent, swap if it isn't alreday => doesn't change previously visited triplet invarient
"""

def wave_sort(arr):
	n = len(arr)
	for i in range(0, len(arr), 2):
		if i > 0 and arr[i-1] > arr[i]:
			arr[i-1], arr[i] = arr[i], arr[i-1]

		if i < n-1 and arr[i+1] > arr[i]:
			arr[i+1], arr[i] = arr[i], arr[i+1]

# Driver program 
arr = [10, 90, 49, 2, 1, 5, 23] 
wave_sort(arr)
print('Wave Sort: ', arr)