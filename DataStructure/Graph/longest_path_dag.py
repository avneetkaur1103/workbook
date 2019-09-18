""" Longest Path in a DAG
Exp: Possible because path follows toplogical ordering and bfs should get the longest path when 
all level path to a node from source is considered and keeping the max """

from collections import defaultdict

class Graph:
	def __init__(self, v):
		self.adj_list = defaultdict(list)
		self.v = v

	def add_edge(self, u, v, wt):
		self.adj_list[u].append((v,wt))

	def topological_sort_util(self, u, visited, stack):
		visited[u] = True
		for v, _ in self.adj_list[u]:
			if not visited[v]:
				self.topological_sort_util(v, visited, stack)
		stack.append(u)

	def topological_sort(self):
		stack = list()
		visited = [False for _ in range(self.v)]

		for u in range(self.v):
			if not visited[u]:
				self.topological_sort_util(u, visited, stack)
		return stack[::-1]

	def longest_path(self, src):
		stack = self.topological_sort()
		dist = [float('-inf') for _ in range(self.v)]
		dist[src] = 0

		for u in stack:  # pick and update neighbours
			if dist[u] == float('-inf'):
				continue
			for v, wt in self.adj_list[u]:
				if dist[v] < dist[u] + wt:
					dist[v] = dist[u] + wt

		print('All dist: ', dist)

if __name__ == '__main__':
	g = Graph(6)
	g.add_edge(0, 1, 5)
	g.add_edge(0, 2, 3)
	g.add_edge(1, 3, 6)
	g.add_edge(1, 2, 2)
	g.add_edge(2, 4, 4)
	g.add_edge(2, 5, 2)
	g.add_edge(2, 3, 7)
	g.add_edge(3, 5, 1)
	g.add_edge(3, 4, -1)
	g.add_edge(4, 5, -2)
	g.longest_path(1)




