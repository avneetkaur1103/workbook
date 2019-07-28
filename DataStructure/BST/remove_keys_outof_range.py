""" Remove BST keys outside the given range. """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

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

def remove_outlier(root, min, max):
	if root:
		root.left = remove_outlier(root.left, min, max)
		root.right = remove_outlier(root.right, min, max)

		if root.key < min:
			return root.right
		elif root.key > max:
			return root.left

	return root

# Driver Code  
if __name__ == '__main__': 
    root = None
    root = insert(root, 6) 
    root = insert(root, -13)  
    root = insert(root, 14)  
    root = insert(root, -8)  
    root = insert(root, 15)  
    root = insert(root, 13)  
    root = insert(root, 7)  
  
    print("Inorder traversal of the given tree is: ",end = "")  
    inorder(root)  
    root = remove_outlier(root, -10, 13)
    print("\nInorder traversal of the given tree is: ",end = "")  
    inorder(root)