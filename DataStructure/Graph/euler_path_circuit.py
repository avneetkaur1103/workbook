""" Fleury’s Algorithm for printing Eulerian Path or Circuit """

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

	def dfs(self, src, visited):
		visited[src] = True
		for v in self.adj_list[src]:
			if not visited[v]:
				self.dfs(v, visited)
		return visited.count(True)

	def allowed(self, edge):
		u, v = edge
		if len(self.adj_list[u]) == 1:
			return True

		visited = [False] * self.v
		n1 = self.dfs(u, visited)
		visited = [False] * self.v
		n2 = self.dfs(u, visited)

		return False if n1>n2 else True

	def euler_tour_util(self, u):
		for v in self.adj_list[u]:
			if self.allowed((u,v)):
				print(f'{u}-{v}')
				self.remove_edge(u, v)
				self.euler_tour_util(v)

	def euler_tour(self):
		u = 0
		for i in range(self.v):
			if len(self.adj_list[i]) & 1:
				u = i
		self.euler_tour_util(u)

if __name__ == '__main__':
	g1 = Graph(4) 
	g1.add_edge(0, 1) 
	g1.add_edge(0, 2) 
	g1.add_edge(1, 2) 
	g1.add_edge(2, 3) 
	g1.euler_tour()
