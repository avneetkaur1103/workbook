""" Given a partially filled 9×9 2D array ‘grid[9][9]’,the goal is to assign digits (from 1 to 9) to the empty cells 
 so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. """
N = 9

def next_free_pos(grid):
	result = None
	for i in range(N):
		for j in range(N):
			if grid[i][j] == 0:
				return i, j
	return result

def is_safe(grid, pos, val):
	r, c = pos
	# check row
	if val in grid[r]:
		return False
	# check column
	if val in [grid[i][c] for i in range(N)]:
		return False
	# check subgrid
	br, bc = r - r % 3, c - c % 3
	for i in range(3):
		for j in range(3):
			if grid[br + i][bc + j] == val:
				return False
	return True

def solve_sudoku(grid):
	pos = next_free_pos(grid)
	if not pos:
		return True

	i, j = pos
	for val in range(1, 10):
		if is_safe(grid, pos, val):
			print(f'Debug: Trying {val} @ {pos}')
			grid[i][j] = val
			if solve_sudoku(grid):
				return True
			grid[i][j] = 0  # Try another no
	return False

def print_board(board):
	for row in board:
		print(row)
	print('')

# Driver main function to test above functions	
if __name__ == "__main__":
	# creating a 2D array for the grid
	grid = [[0 for x in range(9)] for y in range(9)]

	# assigning values to the grid
	grid = [[3, 0, 6, 5, 0, 8, 4, 0, 0],
			[5, 2, 0, 0, 0, 0, 0, 0, 0],
			[0, 8, 7, 0, 0, 0, 0, 3, 1],
			[0, 0, 3, 0, 1, 0, 0, 8, 0],
			[9, 0, 0, 8, 6, 3, 0, 0, 5],
			[0, 5, 0, 0, 9, 0, 6, 0, 0],
			[1, 3, 0, 0, 0, 0, 2, 5, 0],
			[0, 0, 0, 0, 0, 0, 0, 7, 4],
			[0, 0, 5, 2, 0, 6, 3, 0, 0]]

	print('Solvable = ', solve_sudoku(grid))
	print_board(grid)
