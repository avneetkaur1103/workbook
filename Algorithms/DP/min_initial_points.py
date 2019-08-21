""" Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can move across a cell only if we have positive points ( > 0 ). 
Whenever we pass through a cell, points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0)."""

def min_points(arr):
    nR = len(arr)
    nC = len(arr[0])
    dp = [[0 for _ in range(nC)] for _ in range(nR)]

    for i in range(nR-1, -1, -1):
        for j in range(nC-1, -1, -1):
            if i == nR - 1 and j == nC - 1:
                dp[i][j] = 1 if arr[i][j] > 0 else 1 + abs(arr[i][j])
            elif i == nR - 1:
                dp[i][j] = max(dp[i][j + 1] - arr[i][j], 1)  # DP[i][j] = Points Required when we reach next level
            # arr[i][j] = Points available
            elif j == nC - 1:
                dp[i][j] = max(dp[i + 1][j] - arr[i][j], 1)
            else:
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - arr[i][j], 1)

    return dp[0][0]

if __name__ == '__main__':
    points = [[-2, -3, 3],
              [-5, -10, 1],
              [10, 30, -5]]
    points = [[6,-5]]
    print('Minimum points required: ', min_points(points))
