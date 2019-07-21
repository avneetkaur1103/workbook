""" Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K.
     We have to print the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then print -1."""

class Node:
    def __init__(self, value):
        self.key = value
        self.left = self.right = None

def kth_ancestor(root, key, k):
    if not root:
        return None

    if root.key == key or kth_ancestor(root.left, key, k) or kth_ancestor(root.right, key, k):
        k[0] -= 1 if k[0] > 0 else 0
        if not k[0]:
            print('Ancestor: ', root.key)
            return None
        return root
    return None

# Driver Code 
if __name__ == '__main__': 
    root = Node(1)
    root.left = Node(2)  
    root.right = Node(3)  
    root.left.left = Node(4)  
    root.left.right = Node(5)  
  
    k = [2]
    node = 5
  
    # prkth ancestor of given node  
    parent = kth_ancestor(root,node,k)  
