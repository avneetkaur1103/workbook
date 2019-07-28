""" Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
 If the complete Binary Tree is BST, then return the size of the whole tree. """
from collections import namedtuple

INT_MIN = float('-inf')
INT_MAX = float('inf')

class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

node_data = namedtuple('node_data', ['is_bst', 'size', 'min', 'max', 'ans'])

def largest_bst(root):
	if not root:
		return node_data(True, 0, INT_MAX, INT_MIN, 0)

	node_data_left = largest_bst(root.left)
	node_data_right = largest_bst(root.right)

	if node_data_left.is_bst and node_data_right.is_bst and node_data_left.max < root.key < node_data_right.min :
		size = 1 + node_data_right.size + node_data_left.size
		_min = min(node_data_left.min, root.key)  # min w.r.t root for the case of no or only one child
		_max = max(node_data_right.max, root.key)
		return node_data(True, size, _min, _max, size)

	ans = max(node_data_left.size, node_data_right.size)  # pass values found earlier in subtree
	return node_data(False, 0, INT_MAX, INT_MIN, ans)

# Driver Code  
if __name__ == '__main__':  

	"""Let us construct the following Tree 
		60  
		/ \  
		65 70  
	/  
	50 """
	root = Node(60)
	root.left = Node(65)
	root.right = Node(70)
	root.left.left = Node(50)
	print("Size of the largest BST is",
					largest_bst(root).ans)