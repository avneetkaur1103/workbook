""" quick sort """
import random

def partition(arr, left, right):
	ip = random.randrange(left, right)
	arr[ip], arr[right] = arr[right], arr[ip]
	pivot = arr[right]

	i = left - 1
	for j in range(left, right):
		if arr[j] < pivot:
			i += 1
			arr[i], arr[j] = arr[j], arr[i]

	arr[i+1], arr[right] = arr[right], arr[i+1]
	return i+1

def quick_sort(arr, left, right):
	if left < right:
		pivot = partition(arr, left, right)
		quick_sort(arr, left, pivot-1)
		quick_sort(arr, pivot+1, right)

arr = [12, 11, 13, 5, 6] 
#insertion_sort(arr) 
quick_sort(arr, 0, len(arr)-1)
print('Sorted Array: ', arr)