""" Given a directed graph, find out whether the graph is strongly connected or not.
 A directed graph is strongly connected if there is a path between any two pair of vertices."""
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

	def dfs(self, src, visited):
		visited[src] = True
		for v in self.adj_list[src]:
			if not visited[v]:
				self.dfs(v, visited)

	def get_transpose(self):
		g = Graph(self.v)
		for edge in self.edges:
			u, v = edge
			g.add_edge(v, u)
		return g

	def is_scc(self):
		visited = [False]* self.v
		self.dfs(0, visited)
		if False in visited:
			return False

		g = self.get_transpose()
		visited = [False] * g.v
		g.dfs(0, visited)
		if False in visited:
			return False

		return True

	def AP(self):
		n = self.v
		visited = [False] * n
		disc = [MAX_VAL] * n
		low = [MAX_VAL] * n
		parent = [None] * n
		ap = list()

		for i in range(n):
			if not visited[i]:
				self.ap_util(i, visited, disc, low, parent, ap)

		print('APs: ', ap)

	def ap_util(self, u, visited, disc, low, parent, ap):
		self.time += 1
		disc[u] = self.time
		low[u] = self.time
		visited[u] = True
		children = 0

		for v in self.adj_list[u]:
			if not visited[v]:
				children += 1
				parent[v] = u
				self.ap_util(v, visited, disc, low, parent, ap)
				low[u] = min(low[v], low[u])
				if parent[u] == None and children >= 2:
					ap.append(u)
				if parent[u] != None and low[v] >= disc[u]:
					ap.append(u)
			elif not v == parent[u]:  # imp don't consider parent in adjacency
				low[u] = min(low[u], disc[v])

if __name__ == '__main__':
	g1 = Graph(5)
	g1.add_edge(1, 0)
	g1.add_edge(0, 2)
	g1.add_edge(2, 1)
	g1.add_edge(0, 3)
	g1.add_edge(3, 4)
	g1.AP()
	print('-' * 10)
	g2 = Graph(4)
	g2.add_edge(0, 1)
	g2.add_edge(1, 2)
	g2.add_edge(2, 3)
	g2.AP()
	g1 = Graph(5) 
	g1.add_edge(0, 1) 
	g1.add_edge(1, 2) 
	g1.add_edge(2, 3) 
	g1.add_edge(3, 0) 
	g1.add_edge(2, 4) 
	g1.add_edge(4, 2) 
	print('Is SCC: ', g1.is_scc())
	g2 = Graph(4) 
	g2.add_edge(0, 1) 
	g2.add_edge(1, 2) 
	g2.add_edge(2, 3)
	print('Is SCC: ', g2.is_scc())
