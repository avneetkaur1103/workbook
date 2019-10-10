from collections import defaultdict
from queue import Queue

class Graph:
	def __init__(self, n):
		self.adj_list = defaultdict(list)
		self.n = n
	def connect(self, x, y):
		self.adj_list[x].append(y)
		self.adj_list[y].append(x)

	def find_all_distances(self, u):
		visited = [-1]*self.n
		q = Queue()
		q.put((u, 0))
		visited[u] = 1

		while q.qsize():
			u, dist = q.get()
			for v in self.adj_list[u]:
				if visited[v] == -1:
					visited[v] = dist + 6
					q.put((v, visited[v]))
		visited.remove(1)
		print(' '.join(map(str, visited)))


t = int(input())
for i in range(t):
    n,m = [int(value) for value in input().split()]
    graph = Graph(n)
    for i in range(m):
        x,y = [int(x) for x in input().split()]
        graph.connect(x-1,y-1) 
    s = int(input())
    graph.find_all_distances(s-1)

