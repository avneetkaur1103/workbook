""" Given a matrix where every cell represents points. How to collect maximum points using two traversals under following conditions?
Let the dimensions of given grid be R x C.

1) The first traversal starts from top left corner, i.e., (0, 0) and should reach left bottom corner, i.e., (R-1, 0). The second traversal starts from top right corner, i.e., (0, C-1) and should reach bottom right corner, i.e., (R-1, C-1)/

2) From a point (i, j), we can move to (i+1, j+1) or (i+1, j-1) or (i+1, j)

3) A traversal gets all points of a particular cell through which it passes. If one traversal has already collected points of a cell, then the other traversal gets no points if goes through that cell again."""

# A 3D DP problem | memoization
import sys
neighbours = [(1, 0), (1, 1), (1, -1)]

def valid_move(x, y1, y2, nR, nC):
	if 0 <= x < nR and 0 <= y1 < nC and 0 <= y2 < nC:
		return True
	return False

def _print(dp):
	for i in dp:
		for j in i:
			print(i)
		print('---------------')

def max_points(points):
	nR = len(points)
	nC = len(points[0])
	dp = [[[-1 for _ in range(nC)] for _ in range(nC)] for _ in range(nR)]

	def max_point_util(x=nR-1, y1=0, y2=nC-1):
		nonlocal dp
		if not valid_move(x, y1, y2, nR, nC):
			return -sys.maxsize
		if not dp[x][y1][y2] == -1:
			return dp[x][y1][y2]
		if x == 0 and not (y1 == 0 and y2 == nC-1):
			return -sys.maxsize

		earned_here = points[x][y1] + points[x][y2] if not y1 == y2 else points[x][y1]
		temp = 0
		for _, dy1 in neighbours:
			for _, dy2 in neighbours:
				temp = max(temp, max_point_util(x-1, y1+dy1, y2 + dy2))
		dp[x][y1][y2] = temp + earned_here
		_print(dp) if x==nR-1 and y1==0 and y2==nC-1 else None
		return dp[x][y1][y2]
	return max_point_util

if __name__ == '__main__':
	points = [[3, 6, 8, 2],
			[5, 2, 4, 3],
			[1, 1, 20, 10],
			[1, 1, 20, 10],
			[1, 1, 20, 10],
			]
	result = max_points(points)()
	print('Max Points earned: ', result)