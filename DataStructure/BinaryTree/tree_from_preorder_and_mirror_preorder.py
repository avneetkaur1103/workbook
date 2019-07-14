""" Given two arrays that represent Preorder traversals of a full binary tree and its mirror tree,
 	we need to write a program to construct the binary tree using these two Preorder traversals. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def build_tree(preorder, preorderM):
	root = None
	if preorder:
		root = Node(preorder.pop(0))
		preorderM.pop(0)
		if preorder:
			left = preorder[0]
			right = preorderM[0]
			pre_divide_index = preorder.index(right)
			prem_divide_index = preorderM.index(left)
			root.left = build_tree(preorder[:pre_divide_index], preorderM[prem_divide_index:])
			root.right = build_tree(preorder[pre_divide_index:], preorderM[:prem_divide_index])
	return root

# Inorder traversal of tree
def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

if __name__ =="__main__": 
  
	preorder = [1, 2, 4, 5, 3, 6, 7]
	preorderMirror = [1, 3, 7, 6, 2, 5, 4]
	root = build_tree(preorder, preorderMirror)
	print("Inorder Traversal of constructed tree")
	inorder(root)