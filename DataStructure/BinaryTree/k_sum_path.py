""" A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. """

class Node:
    def __init__(self, value):
        self.key = value
        self.left = self.right = None

def k_sum_path(root, k, path=[]):
    if not root:
        return

    path += [root.key]
    sum = 0

    k_sum_path(root.left, k, path) if root.left else None
    k_sum_path(root.right, k, path) if root.right else None
    for j in range(len(path)-1, -1, -1):
        sum += path[j]
        if sum == k:
            k_sum_path.count += 1
            print(k_sum_path.count, " : ", path[j:])
    path.pop()

k_sum_path.count = 0

if __name__ == '__main__': 
  
    root = Node(1)  
    root.left = Node(3)  
    root.left.left = Node(2)  
    root.left.right = Node(1)  
    root.left.right.left = Node(1)  
    root.right = Node(-1)  
    root.right.left = Node(4)  
    root.right.left.left = Node(1)  
    root.right.left.right = Node(2)  
    root.right.right = Node(5)  
    root.right.right.right = Node(2)  
  
    k = 5
    k_sum_path(root, k)




