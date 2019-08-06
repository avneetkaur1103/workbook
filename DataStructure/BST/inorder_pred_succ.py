""" Find in-order successor and predecessor of a BST. """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def insert(root, key):
	if not root:
		return Node(key)
	if root.key == key:
		raise Exception('Duplicate Key')
	if key < root.key:
		root.left = insert(root.left, key)
	if key > root.key:
		root.right = insert(root.right, key)
	return root

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

def get_pred_succ(root, key):
	if root:
		get_pred_succ(root.left, key)
		if root.key < key and (not get_pred_succ.pred or root.key > get_pred_succ.pred):
			get_pred_succ.pred = root.key

		if root.key > key and (not get_pred_succ.succ or root.key < get_pred_succ.succ):
			get_pred_succ.succ = root.key

		get_pred_succ(root.right, key)

if __name__ == '__main__':
	root = None
	root = insert(root, 50) 
	root = insert(root, 30) 
	root = insert(root, 20) 
	root = insert(root, 40) 
	root = insert(root, 70) 
	root = insert(root, 60) 
	root = insert(root, 80) 
	  
	print("Inorder traversal of the given tree")
	inorder(root)
	get_pred_succ.pred = get_pred_succ.succ = None
	get_pred_succ(root, 50)
	print(f'\nPredecessor: {get_pred_succ.pred}\nSuccessor: {get_pred_succ.succ}')



