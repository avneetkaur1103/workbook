""" Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell.
 Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell."""
from queue import Queue
N = 30
def best_path(board):
	dist = [-1]* N
	visited = [False]* N
	parent = [-1]* N
	q = Queue()
	src = 0
	q.put((src, 0));

	while q.qsize():
		print(f'Debug: {q.qsize()} {q.queue}')
		src, d = q.get()
		visited[src] = True
		for i in range(src+1, min(src+7, N)):
			if not visited[i]:
				visited[i] = True
				dist[i] = d + 1
				parent[i] = src
				if not board[i] == -1:
					q.put((board[i], dist[i]))
				else:
					q.put((i, dist[i]))
	print(dist[N-1])

if __name__ == '__main__':
	moves = [-1] * N
	# Ladders 
	moves[2] = 21
	moves[4] = 7
	moves[10] = 25
	moves[19] = 28
	  
	# Snakes 
	moves[26] = 0
	moves[20] = 8
	moves[16] = 3
	moves[18] = 6
	best_path(moves)