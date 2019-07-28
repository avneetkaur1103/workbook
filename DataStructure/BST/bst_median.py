""" Find median of BST in O(n) time and O(1) space. """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def size(root):
	if root:
		l = size(root.left)
		r = size(root.right)
		return 1+l+r
	return 0

def insert(root, key):
	if not root:
		return Node(key)
	if root.key == key:
		raise Exception('Duplicate Key')

	if key < root.key:
		root.left = insert(root.left, key)

	if key > root.key:
		root.right = insert(root.right, key)

def median(root1, root2):
	l = median(root1.left, None) if root1 else None
	r = median(None, root2.right) if root2 else None

	if l or r:
		return l if l else r

	median.left += 1 if root1 else 0
	median.right -= 1 if root2 else 0

	if median.left >= median.right:
		return root1.key

	median(root1.right, None) if root1 else None
	median(None, root2.left) if root2 else None

# Driver Code  
if __name__ == '__main__': 
  
	""" Constructed binary tree is 
		50 
		/ \ 
	30 70 
	/ \ / \ 
	20 40 60 80 """

	root = Node(50)
	insert(root, 30)
	insert(root, 20)
	insert(root, 40)
	insert(root, 70)
	insert(root, 60)
	insert(root, 80)
	insert(root, 100)

	median.left = 0
	median.right = size(root) 
	print("Median of BST is ",median(root, root))

