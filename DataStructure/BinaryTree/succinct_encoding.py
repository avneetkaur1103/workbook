""" A succinct encoding of Binary Tree takes close to minimum possible space.
	The number of structurally different binary trees on n nodes is n’th Catalan number.For large n, this is about 4n;
	thus we need at least about log2 4 n = 2n bits to encode it. A succinct binary tree therefore would occupy 2n+o(n) bits."""

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def encode(root, values, skeleton):
	if not root:
		skeleton.append(0)
		return 

	values.append(root.key)
	skeleton.append(1)
	encode(root.left,values, skeleton)
	encode(root.right, values, skeleton)

def decode(value, skeleton):
	if not value:
		return None
	if skeleton.pop(0):
		root = Node(value.pop(0))
		root.left = decode(value, skeleton)
		root.right = decode(value, skeleton)
		return root
	return None

def preorder(root): 
	if root is not None:
		print("key: %d" % root.key, end='')

		if root.left is not None:
			print ("| left child: %d" % root.left.key, end='')
		if root.right is not None:
			print("| right child %d" % root.right.key)
		preorder(root.left)
		preorder(root.right)

if __name__ == '__main__':
	# Driver Program
	root = Node(10)
	root.left = Node(20)
	root.right = Node(30)
	root.left.left = Node(40)
	root.left.right = Node(50)
	root.right.right = Node(70)
	preorder(root)
	values = list()
	skeleton = list()
	encode(root, values, skeleton)
	print('\nValue: ', values, '\nSkeleton: ', skeleton)
	tree = decode(values, skeleton)
	preorder(tree)

