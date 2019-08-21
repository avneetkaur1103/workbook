""" Given a matrix of characters. Find length of the longest path from a given character, such that all characters in the path are consecutive to each other, i.e., every character in path is next to previous in alphabetical order.
 It is allowed to move in all 8 directions from a cell."""

directions = [(0, 1), (1, 0), ()]

def get_max_len(arr, start):
    nR = len(arr)
    nC = len(arr[0])
    store = list()
    dp = [[0 for _ in range(nR)] for _ in range(nC)]

    for i in range(nR):
        for j in range(nC):
            store.append((arr[i][j], i, j))

    store = sorted(store, reverse=True)

    for i, (elem, x, y) in enumerate(store):
        if i == 0:
            dp[x][y] = 1
        else:
            if i > 0:
                prev = store[i - 1]
                _x, _y = prev[1], prev[2]
                if ord(elem) - ord(prev[0]) == -1 and abs(x-_x) <= 1 and abs(y-_y) <= 1:
                    dp[x][y] = 1 + dp[prev[1]][prev[2]]
    print(store)
    return dp

if __name__ == '__main__':
    mat = [['a', 'c', 'd'],
           ['h', 'b', 'a'],
           ['i', 'g', 'f']]

    print('Ans: ', get_max_len(mat, 1))
