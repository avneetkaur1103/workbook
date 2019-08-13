""" Insertion sort"""

def insertion_sort(arr):
	for i in range(1, len(arr)):
		j = i-1 ; val = arr[i]
		while j >= 0 and arr[j] > val:
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = val

def merge(left, right, arr):
	i = l = r = 0
	ln = len(left); lr = len(right)
	while l < ln and r < lr:
		if left[l] < right[r]:
			arr[i] = left[l]
			l += 1 ; i += 1
		else:
			arr[i] = right[r]
			r += 1 ; i += 1
	while l < ln:
		arr[i] = left[l]
		l += 1 ; i += 1

	while r < lr:
		arr[i] = right[r]
		r += 1 ; i += 1
		

def merge_sort(arr):
	if len(arr) > 1 :
		mid = len(arr)//2
		left = arr[:mid]; right = arr[mid:]
		merge_sort(left)
		merge_sort(right)
		merge(left, right, arr)


arr = [12, 11, 13, 5, 6] 
#insertion_sort(arr) 
merge_sort(arr)
print('Sorted Array: ', arr)