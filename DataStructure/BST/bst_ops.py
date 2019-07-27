""" Search, Insert & Delete in binary tree """

class Node:
	def __init__(self,key):
		self.key = key
		self.left = self.right = None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

def search(root, key):
	if not root:
		raise Exception('Key Not Found')
	if root.key == key:
		return root
	if key < root.key:
		return search(root.left, key)
	if key > root.key:
		return search(root.right, key)

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

def successor(root):
	if root:
		while root.left:
			root = root.left
		return root.key
	return None

def delete(root,key):
	if not root:
		raise Exception('Key not present')
	if key < root.key:
		root.left = delete(root.left, key)
	if key > root.key:
		root.right = delete(root.right, key)

	if root.key == key:
		if not (root.left or root.right):
			return None
		if not root.left:
			return root.right
		elif not root.right:
			return root.left
		else:
			succ = successor(root.right)
			root.key = succ
			root.right = delete(root.right,succ)
			return root

	return root

if __name__ == '__main__':
	# Driver program to test above functions 
	""" Let us create following BST 
	              50 
	           /     \ 
	          30      70 
	         /  \    /  \ 
	       20   40  60   80 """
	  
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
	  
	print("\nDelete 20")
	root = delete(root, 20) 
	print("Inorder traversal of the modified tree")
	inorder(root) 
	  
	print("\nDelete 30")
	root = delete(root, 30) 
	print("Inorder traversal of the modified tree")
	inorder(root) 
	  
	print("\nDelete 50")
	root = delete(root, 50) 
	print("Inorder traversal of the modified tree")
	inorder(root)
	print('Search 70: ', search(root,70).key)