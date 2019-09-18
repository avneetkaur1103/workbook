""" Given a directed graph, check whether the graph contains a cycle or not.
 Your function should return true if the given graph contains at least one cycle, else return false."""
from collections import defaultdict
def add_edge(graph, u, v):
	graph[u].append(v)

def dfs(src, graph, visited, rec_stack):
	visited[src] = True
	rec_stack[src] = True

	for v in graph[src]:
		if not visited[v]:
			dfs(v, graph, visited, rec_stack)
		elif v in rec_stack:
			return False
	return True

def is_cyclic(graph, V):
	rec_stack = [False] * V
	visited = [False] * V

	for key in graph.keys():
		if not visited[key]:
			if not dfs(key, graph, visited, rec_stack):
				return False
	return True

if __name__ == '__main__':
	graph = defaultdict(list)
	V = 4
	add_edge(graph, 0, 1) 
	add_edge(graph, 0, 2) 
	add_edge(graph, 1, 2) 
	add_edge(graph, 2, 0)
	add_edge(graph, 2, 3) 
	add_edge(graph, 3, 3)
	print('Is Cyclic: ', is_cyclic(graph, V))
