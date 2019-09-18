""" Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph.
 The graph may contain negative weight edges. - Bellman-Ford way for directed graph"""
from collections import defaultdict

class Graph:
	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v
		self.edges = list()

	def add_edge(self, u, v, wt):
		self.adj_list[u].append((v,wt))
		# self.adj_list[v].append((u,wt))
		self.edges.append((u,v,wt))

def bellman_ford(graph, src):
	dist = [float('inf')] * graph.v
	e = len(graph.edges)

	dist[src] = 0
	for _ in range(graph.v-1):
		for edge in graph.edges:
			u, v, wt = edge
			if not dist[u] == float('inf') and dist[v] > dist[u] + wt:
				dist[v] = dist[u] + wt

	for edge in graph.edges:
		u, v, wt = edge
		if not dist[u] == float('inf') and dist[v] > dist[u] + wt:
			dist[v] = dist[u] + wt

	print(dist)

if __name__ == '__main__':
	graph = Graph(5)
	graph.add_edge(0,1,-1)
	graph.add_edge(0,2,4)
	graph.add_edge(1,2,3)
	graph.add_edge(1,3,2)
	graph.add_edge(1,4,2)
	graph.add_edge(3,2,5)
	graph.add_edge(3,1,1)
	graph.add_edge(4,3,-3)

	bellman_ford(graph, 0)