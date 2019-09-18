""" Ford-Fulkerson Algorithm for Maximum Flow Problem """
from queue import Queue
import copy
def bfs(graph, src, sink, parent):
	n = len(graph)  # no of nodes
	visited = [False] * n 
	q = Queue()
	parent[src] = -1
	q.put(src)

	while q.qsize():
		u = q.get()
		if u == sink:
			return True
		for v, val in enumerate(graph[u]):
			if not visited[v] and val > 0:
				visited[v] = True
				parent[v] = u
				q.put(v)
	return False

def max_flow(graph, src, sink):
	n = len(graph)
	res = copy.deepcopy(graph)
	parent = [-1] * n
	max_flow = 0
	while(bfs(res, src, sink, parent)):
		t, path_flow_min = sink, float('inf')
		while not t == src:
			path_flow_min = min(path_flow_min, graph[parent[t]][t])
			t = parent[t]
		max_flow += path_flow_min
		# update residual graph
		t = sink
		while not t == src:
			res[parent[t]][t] -= path_flow_min
			res[t][parent[t]] += path_flow_min
			t = parent[t]

	return [(u,v) for u in range(n)  for v in range(n) if not res[u][v] and graph[u][v]]

if __name__ == '__main__':
	graph = [[0, 16, 13, 0, 0, 0], 
	        [0, 0, 10, 12, 0, 0], 
	        [0, 4, 0, 0, 14, 0], 
	        [0, 0, 9, 0, 0, 20], 
	        [0, 0, 0, 7, 0, 4], 
	        [0, 0, 0, 0, 0, 0]]
	result =  max_flow(graph, 0, 5)
	for val in result:
		print(val)