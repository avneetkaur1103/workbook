""" Given a matrix of characters. Find length of the longest path from a given character, such that all characters in the path are consecutive to each other, i.e., every character in path is next to previous in alphabetical order.
 It is allowed to move in all 8 directions from a cell."""

def get_max_len(arr, start):
    ''' Works for no duplicate '''
    nR = len(arr)
    nC = len(arr[0])
    store = list()
    dp = [[1 for _ in range(nR)] for _ in range(nC)]

    for i in range(nR):
        for j in range(nC):
            store.append((arr[i][j], i, j))

    store = sorted(store, reverse=True)

    for i, (elem, x, y) in enumerate(store):
        if i > 0:
            prev = store[i - 1]
            prev_elem, _x, _y = prev
            if ord(prev_elem) - ord(elem) == 1 and abs(x-_x) < 2 and abs(y-_y) < 2:
                dp[x][y] = 1 + dp[_x][_y]
    print(store)
    return dp

neighbours = [(-1,0), (1,0), (0,-1), (0,1), (-1,-1), (1,1), (1,-1), (-1,1)]

def is_valid(x,y, dx, dy):
    if -1 < x+dx < 3 and -1 < y+dy < 3:
        return True
    return False

def get_max_len_dp(arr, start):
    nR = len(arr)
    nC = len(arr[0])
    store = list()
    dp = [[1 for _ in range(nR)] for _ in range(nC)]

    for i in range(nR):
        for j in range(nC):
            store.append((arr[i][j], i, j))

    store = sorted(store, reverse=True)

    for elem, x, y in store:
        for dx, dy in neighbours:
            if is_valid(x, y, dx, dy):
                next_element = arr[x+dx][y+dy]
                if ord(next_element) - ord(elem) == -1 and 1 + dp[x][y] > dp[x+dx][y+dy]:
                    dp[x+dx][y+dy] = 1 + dp[x][y]

    return dp

if __name__ == '__main__':
    mat = [['a', 'c', 'd'],
           ['h', 'b', 'a'],
           ['i', 'g', 'f']]

    print('Ans: ', get_max_len_dp(mat, 1))
