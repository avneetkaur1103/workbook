""" Topological Sort """
from collections import defaultdict

class Graph:
	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v

	def add_edge(self, u, v):
		self.adj_list[u].append(v)

	def topological_sort_util(self, u, visited, stack):
		visited[u] = True
		for v in self.adj_list[u]:
			if not visited[v]:
				self.topological_sort_util(v, visited, stack)
		stack.append(u)

	def topological_sort(self):
		stack = list()
		visited = [False for _ in range(self.v)]

		for u in range(self.v):
			if not visited[u]:
				self.topological_sort_util(u, visited, stack)

		for v in reversed(stack):
			print(v, sep=' ')

if __name__ == '__main__':
	g= Graph(6) 
	g.add_edge(5, 2); 
	g.add_edge(5, 0); 
	g.add_edge(4, 0); 
	g.add_edge(4, 1); 
	g.add_edge(2, 3); 
	g.add_edge(3, 1);
	g.topological_sort()