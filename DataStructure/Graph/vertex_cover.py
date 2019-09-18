""" A vertex cover of an undirected graph is a subset of its vertices such that for every edge (u, v) of the graph, either ‘u’ or ‘v’ is in vertex cover.
Although the name is Vertex Cover, the set covers all edges of the given graph. Given an undirected graph, the vertex cover problem is to find minimum size vertex cover."""

MAX_VAL = float('inf')
from collections import defaultdict

class Graph:
	time = 0

	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v
		self.edges = list()

	def add_edge(self, u, v):
		self.adj_list[u].append(v)
		self.adj_list[v].append(u)
		self.edges.append((u, v))

	def remove_edge(self, u, v):
		self.adj_list[u].remove(v)
		self.adj_list[v].remove(u)
		self.edges.remove((u, v)) if (u, v) in self.edges else None

	def max_degree(self):
		max_u, max_degree = -1, -1
		for u in range(self.v):
			if max_degree < len(self.adj_list[u]):
				max_u, max_degree = u, len(self.adj_list[u])
		return max_u, max_degree

	def v_cov(self):
		cover = list()
		u, degree = self.max_degree()
		while degree > 0:
			cover.append(u)
			for v in self.adj_list[u][:]:
				self.remove_edge(u, v)
			u, degree = self.max_degree()
		return cover

if __name__ == '__main__':
	g = Graph(7) 
	g.add_edge(0, 1)
	g.add_edge(0, 2)
	g.add_edge(1, 3)
	g.add_edge(3, 4)
	g.add_edge(4, 5)
	g.add_edge(5, 6)
	print('V Cov:', g.v_cov())