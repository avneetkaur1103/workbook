""" Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.
{"baa", "abcd", "abca", "cab", "cad"} = > b,d,a,c """
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

		return list(reversed(stack))
			

if __name__ == '__main__':
	n = 3  # no of chars
	words = ["caa", "aaa", "aab"] 
	g= Graph(n) 
	for i in range(len(words)-1):
		word1, word2 = words[i:i+2]
		for x,y in zip(word1, word2):
			if not x == y:
				g.add_edge(ord(x)-ord('a'), ord(y)-ord('a'))

	result = g.topological_sort()
	for v in result:
		print(chr(v+ord('a')), end=' ')
	