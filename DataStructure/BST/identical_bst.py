"""Given two arrays which represent a sequence of keys. Imagine we make a Binary Search Tree (BST) from each array.
 We need to tell whether two BSTs will be identical or not without actually constructing the tree. """

INT_MIN = float('-inf')
INT_MAX = float('inf')

def is_identical(arr1, arr2, min, max):
	if not arr1 and arr2:
		return True

	i = j = None
	for x in range(len(arr1)):
		if min < arr1[x] < max:
			i = x
			break

	for x in range(len(arr2)):
		if min < arr2[x] < max:
			j = x
			break

	if not i and not j:
		return True

	if not (i and j) or arr1[i] != arr2[j]:
		return False

	curr = arr1[i]
	arr1.pop(i); arr2.pop(j)

	return is_identical(arr1, arr2, min, curr) and is_identical(arr1, arr2, curr, max)

if __name__ == '__main__':
	a = [8, 3, 6, 1, 4, 7, 10, 14, 13]  
	b = [8, 10, 14, 3, 6, 4, 1, 7, 13]
	print('Is Identical BST: ', is_identical(a, b, INT_MIN, INT_MAX))






