""" Construct BST from given preorder traversal  """

class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

def first_greater_on_right(preorder, start, end, key):
	first_greater_index = start
	while first_greater_index < end and preorder[first_greater_index] < key:
		first_greater_index += 1
	return first_greater_index

def to_tree(preorder, start, end):
	if start < end:
		root = Node(preorder[start])
		index = first_greater_on_right(preorder, start+1, end, root.key)
		root.left = to_tree(preorder, start+1, index)
		root.right = to_tree(preorder, index, end)
		return root
	return None

# Driver program to test above function
pre = [10, 5, 1, 7, 40, 50]

root = to_tree(pre, 0, len(pre))
print("Inorder traversal of the constructed tree:")
inorder(root)


