""" Prim's mst algorithm. """
import heapq, sys

def decrease_key(heap, old_tuple, new_tuple):
	if old_tuple in heap:
		i = heap.index(old_tuple)
		heap[i] = new_tuple
		heapq._siftup(heap, i)
		heapq._siftdown(heap, 0, i)

def mst(graph):
	n = len(graph)
	parent = [None] * n 
	in_spt = [False] * n
	dist = [sys.maxsize] * n
	heap = [(sys.maxsize, i) for i in range(n)]  # [val, vertex]
	dist[0] = 0; heap[0] = (0, 0)
	# heapq.heapify(heap)

	for _ in range(n):
		val, u = heapq.heappop(heap)
		if not in_spt[u]:
			in_spt[u] = True
			for v, w in enumerate(graph[u]):
				if 0 < w and w + val < dist[v]:
					parent[v] = u
					decrease_key(heap, (dist[v], v), (w + val, v))
					dist[v] = val + w
	for v in range(1, n):
		print(f'{v}-{parent[v]}|{dist[v]}')

if __name__ == '__main__':
	graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
	         [4, 0, 8, 0, 0, 0, 0, 11, 0],
	         [0, 8, 0, 7, 0, 4, 0, 0, 2],
	         [0, 0, 7, 0, 9, 14, 0, 0, 0],
	         [0, 0, 0, 9, 0, 10, 0, 0, 0],
	         [0, 0, 4, 14, 10, 0, 2, 0, 0],
	         [0, 0, 0, 0, 0, 2, 0, 1, 6],
	         [8, 11, 0, 0, 0, 0, 1, 0, 7],
	         [0, 0, 2, 0, 0, 0, 6, 7, 0]
	         ]
	mst(graph)
