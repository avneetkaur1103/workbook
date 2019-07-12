""" Given Inorder and Preorder traversals of a binary tree, print Postorder traversal."""

class Node:
	def __init__(self,value):
		self.key = value
		self.left = self.right = None

def print_postorder(inOrder, preOrder):
	if preOrder:
		index = inOrder.index(preOrder[0])
		print_postorder(inOrder[:index], preOrder[1:index+1])
		print_postorder(inOrder[index+1:], preOrder[index+1:])
		print(preOrder[0], end = ' ')

if __name__ == '__main__':
	# Driver Code 
	inorder = [4, 2, 5, 1, 3, 6]; 
	preorder = [1, 2, 4, 5, 3, 6]; 
	print("Postorder traversal ")
	print_postorder(inorder, preorder) 