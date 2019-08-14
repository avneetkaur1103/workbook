""" Given three arrays sorted in non-decreasing order, print all common elements in these arrays. """

def intersection(arr1, arr2, arr3):
	l1 = len(arr1); l2 = len(arr2); l3 = len(arr3)
	i = j = k = 0
	while i < l1 and j < l2 and k < l3:
		if arr1[i] == arr2[j] == arr3[k]:
			print(arr1[i], end=' ')
			i += 1; j += 1; k += 1

		elif arr1[i] < arr2[j]:
			i += 1
		elif arr2[j] < arr3[k]:
			j += 1
		else:
			k += 1

# Driver program to check above function 
ar1 = [1, 5, 10, 20, 40, 80] 
ar2 = [6, 7, 20, 80, 100] 
ar3 = [3, 4, 15, 20, 30, 70, 80, 120]
intersection(ar1, ar2, ar3)