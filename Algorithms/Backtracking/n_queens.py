''' The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.'''
N = 4

def is_safe(sol, row, col):
	if row == 0:
		return True
	# left diag
	d = min(row - 0, col - 0)
	if sum(sol[row - i][col - i] for i in range(1, d + 1)) > 0:
		return False
	# right diag
	d = min(row - 0, N - 1 - col)
	if sum(sol[row - i][col + i] for i in range(1, d + 1)) > 0:
		return False
	# check column
	if sum(sol[i][col] for i in range(row)) > 0:
		return False
	return True

def nqueen(sol, row):
	if row == N:
		return True

	for col in range(N):
		if not is_safe(sol, row, col):
			continue
		sol[row][col] = 1
		if nqueen(sol, row + 1):
			return True
		sol[row][col] = 0
	return False

def print_board(board):
	for row in board:
		print(row)
	print('')

if __name__ == '__main__':
	board = [[0 for _ in range(N)] for _ in range(N)]
	print('nqueen= ', nqueen(board, 0))
	print_board(board)
