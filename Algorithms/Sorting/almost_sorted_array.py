""" Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions,
 i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. """

def search(arr, key):
	if arr:
		mid = len(arr)//2

		if arr[mid] == key:
 			return mid
		if mid > 0 and arr[mid-1] == key:
			return mid - 1
		if mid + 1 < len(arr) and arr[mid+1] == key:
			return mid + 1

		if key < arr[mid]:
			arr = arr[:mid-1]

		if key > arr[mid]:
			arr = arr[mid+2:]
	return -1

arr = [3, 2, 10, 4, 40]
result = search(arr, 4)
print('Key present at: ', result)

