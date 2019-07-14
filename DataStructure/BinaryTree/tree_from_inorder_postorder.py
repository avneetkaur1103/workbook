""" Given Postorder and Inorder traversals, construct the tree. """
from iterative_preorder import preorder

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def build_tree(inorder, postorder):
	if postorder:
		root = Node(postorder.pop())
		root.right = build_tree(inorder[inorder.index(root.key)+1:], postorder) if inorder[inorder.index(root.key)+1:] else None
		root.left = build_tree(inorder[:inorder.index(root.key)], postorder) if inorder[:inorder.index(root.key)] else None
		return root
	return None

# Driver code  
if __name__ == '__main__': 
	inorder = [4, 8, 2, 5, 1, 6, 3, 7]
	post = [8, 4, 5, 2, 6, 7, 3, 1]
  
	root = build_tree(inorder, post)
  
	print("Preorder of the constructed tree :", preorder(root))

