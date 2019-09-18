""" The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once."""
N = 8
move_x = [2, 1, -1, -2, -2, -1, 1, 2] 
move_y = [1, 2, 2, 1, -1, -2, -2, -1] 
neighbours = [val for val in zip(move_x,move_y)]
def print_board(board): 
    for i in range(N): 
        print(board[i])
    print('')

def tour(sol, count, pos):
    x, y = pos
    if count == N**2:
        sol[x][y] = count
        return True

    sol[x][y] = count
    for dx,dy in neighbours:
        if 0 <= x + dx < N and 0 <= y + dy < N and sol[x + dx][y + dy] == -1:
            print(f'Debug: {x+dx}, {y+dy}, {count}')
            if tour(sol, count+1, (x+dx, y+dy)):
                return True
    sol[x][y] = -1
    return False

if __name__ == '__main__':
    sol = [[-1 for _ in range(N)] for _ in range(N)]
    print('Result = ', tour(sol, 1, (0,0)))
    print_board(sol)
