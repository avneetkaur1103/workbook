""" There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n).
 The complexity should be O(log(n))."""

def median(arr1, arr2):
    if not len(arr1) == len(arr2):
        raise Exception('Unequal arrays')
    else:
        mid = len(arr1) // 2
    xM = arr1[mid]
    yM = arr2[mid]
    if xM == yM:
        return (xM + yM) / 2

    if len(arr1) == 1:
        return (arr1[0] + arr2[1]) / 2
    elif len(arr1) == 2:
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2
    else:
        if xM < yM:
            print('Debug: ', arr1[mid:], arr2[:mid + 1])
            return median(arr1[mid:], arr2[:mid + 1])
        else:
            print('Debug: ', arr1[:mid + 1], arr2[mid:])
            return median(arr1[:mid + 1], arr2[mid:])

if __name__ == '__main__':
    a = [1, 12, 15, 26, 38]
    b = [2, 13, 17, 30, 45]
    print('Median: ', median(a, b))
