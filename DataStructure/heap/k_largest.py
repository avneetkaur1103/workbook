""" K largest element of an array. """

from heapq import heappush, heappop, heapify, heapreplace

# heapreplace  => heappop() + heappush -> heap size unchanged

def k_largest(arr, k):
	heap = arr[:k]
	heapify(heap)

	for x in arr[k:]:
		if x > heap[0]:
			heapreplace(heap, x)

	res = [heappop(heap) for _ in range(len(heap))]
	return res

if __name__ == '__main__':
	arr = [i for i in range(11)]
	res = k_largest(arr, 3)
	print(f'K Largest: {res}')
