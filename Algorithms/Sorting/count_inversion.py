""" Count inversions of an array """

def merge(left, right, arr, inversions_set):
	nleft = len(left)
	nright = len(right)
	i = j = k = 0
	inversions = 0
	print(f'Debug: Left:{left} Right:{right}', end=' ')
	while i < nleft and j < nright:
		if left[i] < right[j]:
			arr[k] = left[i]
			i += 1; k += 1
		else:
			arr[k] = right[j]
			inversions += len(left) - i
			inversions_set.update([(k, right[j]) for k in left[i:]])
			j += 1; k += 1

	while i < nleft:
		arr[k] = left[i]
		i += 1; k +=1
	while j < nright:
		arr[k] = right[j]
		j += 1; k+=1
	print(f'Inversion: {inversions}|{inversions_set}')
	return inversions

def count_inversions(arr, inversions_set):
	if len(arr) > 1:
		mid = len(arr)//2
		left = arr[:mid]
		right = arr[mid:]
		inversions = count_inversions(left, inversions_set)
		inversions += count_inversions(right, inversions_set)
		inversions += merge(left, right, arr, inversions_set)
		return inversions
	return 0

arr = [1, 20, 6, 4, 5] 
inversions_set = set()
res = count_inversions(arr, inversions_set)
print('Arr: ', arr)
print('Inversion Set: ', inversions_set)
print('Inversion Count: ', res)