""" Given a 2D array, find the maximum sum subarray in it. """
import sys

def kadane(arr):
    max_global = -sys.maxsize
    sum_unto = 0
    start, end = -1, -1
    head = 0
    for i in range(len(arr)):
        sum_unto += arr[i]
        if arr[i] > sum_unto:
            sum_unto = arr[i];
            head = i
        if sum_unto > max_global:
            max_global = sum_unto;
            start = head;
            end = i
    return max_global, start, end

def max_rect(arr):
    nR = len(arr)
    nC = len(arr[0])

    temp = [None] * nR
    global_max = -sys.maxsize
    start, end = -1, -1

    for i in range(nC):
        for j in range(i, nC):
            temp = [sum(arr[k][i:j]) for k in range(nR)]
            local_max, _start, _end = kadane(temp)
            if local_max > global_max:
                global_max = local_max
                start = _start;
                end = _end
    return global_max, start, end

if __name__ == '__main__':
    M = [[1, 2, -1, -4, -20],
         [-8, -3, 4, 2, 1],
         [3, 8, 10, 1, 3],
         [-4, -1, 1, 7, -6]]

    print('Max Rect', max_rect(M))
