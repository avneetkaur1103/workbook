""" Given Postorder and Inorder traversals, construct the tree. """
from iterative_preorder import preorder
from inorder_iterative import inorder

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def build_tree(inorder, postorder): # based on how can we extract next root from level-order
	root = None
	if inorder:
		for i in range(len(inorder)):
			if inorder[i] in levelorder:
				root = Node(inorder[i])
		if root:
			indx = inorder.index(root.key)
			root.left = build_tree(inorder[:indx], postorder) if inorder[:indx] else None
			root.right = build_tree(inorder[indx+1:], postorder) if inorder[indx+1:] else None
	return root

# Driver code  
if __name__ == '__main__':
	levelorder = [20, 8, 22, 4, 12, 10, 14]
	_inorder = [4, 8, 10, 12, 14, 20, 22]
  
	root = build_tree(_inorder, levelorder)
  
	print("Preorder of the constructed tree : ")
	inorder(root)

