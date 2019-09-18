# Python Program for Floyd Warshall Algorithm 
import copy

# Number of vertices in the graph 
V = 4
# Define infinity as the large enough value. This value will be 
# used for vertices not connected to each other 
INF = float('inf')

# Solves all pair shortest path via Floyd Warshall Algorithm 
def floydWarshall(graph):
	dist = copy.deepcopy(graph)
	for k in range(V):
		for i in range(V):
			for j in range(V):
				dist[i][j] = min(dist[i][j],
								 dist[i][k] + dist[k][j]
								 )
	printSolution(dist)

# A utility function to print the solution 
def printSolution(dist):
	for val in dist:
		print(val)

# Driver program to test the above program 
# Let us create the following weighted graph 
""" 
            10 
       (0)------->(3) 
        |         /|\ 
      5 |          | 
        |          | 1 
       \|/         | 
       (1)------->(2) 
            3           """
graph = [[0, 5, INF, 10],
		 [INF, 0, 3, INF],
		 [INF, INF, 0, 1],
		 [INF, INF, INF, 0]
		 ]
# Print the solution 
floydWarshall(graph);
