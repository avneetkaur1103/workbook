""" Given that integers are being read from a data stream. Find median of all the elements read so far starting from the first integer till the last integer.
 This is also called Median of Running Integers. The data stream can be any source of data, example: a file, an array of integers, input stream etc."""
import heapq

def median(arr):
	max_heap = []
	min_heap = []
	results = []

	heapq.heappush(min_heap, arr[0])
	results.append(arr[0])

	for i in arr[1:]:
		max_l = len(max_heap)
		min_l = len(min_heap)

		if max_l > min_l:
			if i < max_heap[0]:
				temp = max_heap[0]
				heapq._heapreplace_max(max_heap, i)
				min_heap.heappush(temp)
			else:
				heapq.heappush(min_heap, i)

			results.append((max_heap[0] + min_heap[0])/2)
			continue

		elif max_l < min_l:
			if i > min_heap[0]:
				temp = min_heap[0]
				heapq.heapreplace(min_heap, i)
				max_heap.append(temp)
				heapq._siftdown_max(max_heap, 0, max_l-1)
			else:
				max_heap.append(i)
				heapq._siftdown_max(max_heap, 0, max_l)

			results.append((max_heap[0] + min_heap[0])/2)
			continue

		else:
			if i > min_heap[0]:
				heapq.heappush(min_heap, i)
				results.append(min_heap[0])
			else:
				max_heap.append(i)
				heapq._siftdown_max(max_heap, 0, max_l)
				results.append(max_heap[0])
	return results

if __name__ == '__main__':
	a = [5, 15, 10, 20, 3]
	results = median(a)
	print('Medians: ', results)







