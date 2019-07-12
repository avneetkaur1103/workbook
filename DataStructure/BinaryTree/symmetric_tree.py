""" Given a binary tree, check whether it is a mirror of itself. """
class Node:
	def __init__(self,value):
		self.key = value
		self.left = self.right = None 

def is_mirror(root1, root2):
	if not root1 and not root2:
		return True

	if root1 and root2:
		return root1.key == root2.key and is_mirror(root1.left, root2.right) and is_mirror(root1.right,root2.left)
	return False

def is_symmetric(root):
	return is_mirror(root.left, root.right)

if __name__ == '__main__':
	root = Node(1) 
	root.left = Node(2) 
	root.right = Node(2) 
	root.left.left = Node(3) 
	root.left.right = Node(4) 
	root.right.left = Node(4) 
	root.right.right = Node(3) 
	print('Is Symmetric = ', is_symmetric(root))