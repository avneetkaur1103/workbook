""" Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only increment data values in any node """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def adjust_increment(root, diff):
	if root:
		if root.left:
			root.left.key += diff
			adjust_increment(root.left, diff)
		elif root.right:
			root.right.key += diff
			adjust_increment(root.right, diff)

def convert_to_children_sum(root):
	if root:
		left_key = convert_to_children_sum(root.left)
		right_key = convert_to_children_sum(root.right)
		diff = root.key - (left_key+right_key)
		if diff < 0:
			root.key += abs(diff)
		elif diff > 0:
			adjust_increment(root, diff)
		return root.key
	return 0

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)
		
# Driver Code  
if __name__ == '__main__': 
	root            = Node(50)
	root.left       = Node(7)
	root.right      = Node(2)
	root.left.left  = Node(3)
	root.left.right = Node(5)
	root.right.left = Node(1)
	root.right.right = Node(30)
  
	print("Inorder traversal before conversion")
	inorder(root)
	convert_to_children_sum(root)
	print("\nInorder traversal after conversion ")
	inorder(root)


