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
	in_mst = [False] * n
	cost = [sys.maxsize] * n
	heap = [(sys.maxsize, i) for i in range(n)]  # [val, vertex]
	cost[0] = 0; heap[0] = (0, 0)
	# heapq.heapify(heap)

	for _ in range(n):
		val, u = heapq.heappop(heap)
		if not in_mst[u]:
			in_mst[u] = True
			for v, w in enumerate(graph[u]):
				if 0 < w < cost[v]:
					parent[v] = u
					decrease_key(heap, (cost[v], v), (w, v))
					cost[v] = w
	for v in range(1, n):
		print(f'{v}-{parent[v]}')

if __name__ == '__main__':
	graph = [ [0, 2, 0, 6, 0], 
            [2, 0, 3, 8, 5], 
            [0, 3, 0, 0, 7], 
            [6, 8, 0, 0, 9], 
            [0, 5, 7, 9, 0]]
	mst(graph)
