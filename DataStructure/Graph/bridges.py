"""An edge in an undirected connected graph is a bridge iff removing it disconnects the graph.
 For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components."""
MAX_VAL = float('inf')
from collections import defaultdict

class Graph:
	time = 0

	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v
		self.edges = list()
		Graph.time = 0

	def add_edge(self, u, v):
		self.adj_list[u].append(v)
		self.adj_list[v].append(u)
		self.edges.append((u, v))

	def all_bridges(self):
		n = self.v
		visited = [False] * n
		disc = [MAX_VAL] * n
		low = [MAX_VAL] * n
		parent = [False] * n
		bridges = list()
		for i in range(n):
			if not visited[i]:
				self.bridge_util(i, visited, disc, low, parent, bridges)
		print('Bridges: ', bridges)

	def bridge_util(self, u, visited, disc, low, parent,  bridges):
		self.time += 1
		disc[u] = self.time
		low[u] = self.time
		visited[u] = True

		for v in self.adj_list[u]:
			if not visited[v]:
				parent[v] = u
				self.bridge_util(v, visited, disc, low, parent, bridges)
				low[u] = min(low[v], low[u])
				if low[v] > disc[u]:
					bridges.append((u, v))
			elif not parent[u] == v:  # don't go back to parent which introduced it
				low[u] = min(low[u], disc[v])

if __name__ == '__main__':
	g1 = Graph(5) 
	g1.add_edge(1, 0) 
	g1.add_edge(0, 2) 
	g1.add_edge(2, 1) 
	g1.add_edge(0, 3) 
	g1.add_edge(3, 4) 
	g1.all_bridges()
	print('-' * 10)
	g3 = Graph(7)
	g3.add_edge(0, 1)
	g3.add_edge(1, 2)
	g3.add_edge(2, 0)
	g3.add_edge(1, 3)
	g3.add_edge(1, 4)
	g3.add_edge(1, 6)
	g3.add_edge(3, 5)
	g3.add_edge(4, 5)
	g3.all_bridges()