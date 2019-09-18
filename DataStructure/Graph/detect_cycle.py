""" Detect cycles in graph - Disjoint Set-Union way """
from collections import defaultdict

class DisjointSets:
	def __init__(self, size):
		self.parent = [-1 for _ in range(size)]
		self.rank = [0 for _ in range(size)]

	def union(self, i, j):
		x = self.find(i)
		y = self.find(j)
		if x == y:
			return False
		if self.rank[x] > self.rank[y]:
			self.parent[y] = x
		elif self.rank[x] < self.rank[y]:
			self.parent[x] = y
		else:
			self.parent[x] = y
			self.rank[y] += 1
		return True

	def find(self, i):
		while not self.parent[i] == -1:
			i = self.parent[i]
		return i

class Graph:
	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v
		self.edges = list()

	def add_edge(self, u, v):
		self.adj_list[u].append(v)
		self.adj_list[v].append(u)
		self.edges.append((u,v))

	def is_cyclic(self):
		ds = DisjointSets(self.v)
		for u, v in self.edges:
			if not ds.union(u, v):
				return True
		return False

if __name__ == '__main__':
	g = Graph(3)
	g.add_edge(0, 1) 
	g.add_edge(1, 2) 
	# g.add_edge(2, 0)
	print('Is Cyclic: ', g.is_cyclic())
