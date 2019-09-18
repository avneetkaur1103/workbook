""" A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint.
 A maximum matching is a matching of maximum size (maximum number of edges). In a maximum matching,
if any edge is added to it, it is no longer a matching. There can be more than one maximum matchings for a given Bipartite Graph."""

def bpm(graph, person, matchR, seen):
	for idx, jobs in enumerate(graph[person]):
		if jobs and not seen[idx]:
			seen[idx] = True
			if matchR[idx] < 0 or bpm(graph, matchR[idx], matchR, seen):
				return True
	return False

def maxbpm(graph):
	n = len(graph)
	matchR = [-1]* n
	result = 0
	for i in range(n):
		seen = [False]*n
		if bpm(graph, i, matchR, seen):
			result += 1
	return result

graph =[[0, 1, 1, 0, 0, 0], 
          [1, 0, 0, 1, 0, 0], 
          [0, 0, 1, 0, 0, 0], 
          [0, 0, 1, 1, 0, 0], 
          [0, 0, 0, 0, 0, 0], 
          [0, 0, 0, 0, 0, 1]] 
print('Max matching:', maxbpm(graph))