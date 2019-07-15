""" Given a Binary Tree, change the value in each node to sum of all the values in the nodes in the left subtree including its own. """
class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

def to_sum_tree(root):
	if not root:
		return 0

	left_sum = to_sum_tree(root.left) if root.left else 0
	right_sum = to_sum_tree(root.right) if root.right else 0

	root.key += left_sum

	return root.key + right_sum

# Driver Code  
if __name__ == '__main__': 
      
    """ Let us con below tree  
                  1  
                / 	\  
                2 	3  
               / \	 \  
              4   5   6 """
    root = Node(1)  
    root.left = Node(2)  
    root.right = Node(3)  
    root.left.left = Node(4)  
    root.left.right = Node(5)  
    root.right.right = Node(6)  
  
    to_sum_tree(root)  
  
    print("Inorder traversal of the modified tree is")  
    inorder(root) 