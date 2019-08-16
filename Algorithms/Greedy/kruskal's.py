""" Kruskal’s Minimum Spanning Tree Algorithm. """

def find(parent, i):
	while not parent[i] == -1:
		i = parent[i]
	return i

def union(parent, rank, u, v):
	xroot = find(parent, u)
	yroot = find(parent, v)

	if rank[xroot] > rank[yroot]:
		parent[yroot] = xroot
	elif rank[yroot] > rank[xroot]:
		parent[xroot] = yroot
	else:
		parent[yroot] = xroot
		rank[xroot] += 1

class Graph:
	def __init__(self, v):
		self.v = v
		self.edges = list()

	def add_edge(self, u, v, w):
		self.edges.append((w, u, v))

	def mst(self):
		results = list()
		parent = [-1] * self.v
		rank = [0] * self.v

		self.edges = sorted(self.edges)

		while len(results) < self.v - 1: # assuming it's connected
			w, u, v = edge = self.edges.pop(0)
			pu = find(parent, u)
			pv = find(parent, v)

			if pu == pv:
				continue
			union(parent, rank, u, v)
			results.append(edge)

		for w, u, v in results:
			print(f'{u}-{v}|{w}')

if __name__ == '__main__':
	g = Graph(4)
	g.add_edge(0, 1, 10)
	g.add_edge(0, 2, 6) 
	g.add_edge(0, 3, 5) 
	g.add_edge(1, 3, 15) 
	g.add_edge(2, 3, 4)
	g.mst()


