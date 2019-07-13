""" Iterative preorder traversal """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

class Stack:
	def __init__(self):
		self.data = list()

	def push(self,val):
		self.data.append(val)

	def pop(self):
		if not len(self):
			raise Exception('Empty Stack')
		return self.data.pop()

	def __len__(self):
		return len(self.data)

	def top(self):
		if not len(self):
			raise Exception('Empty Stack')
		return self.data[-1]

	def empty(self):
		return not self.data

def preorder(root):
	stack = Stack()
	stack.push(root)
	result = list()
	while not stack.empty():
		curr = stack.pop()
		result.append(curr.key)
		stack.push(curr.right) if curr.right else None
		stack.push(curr.left) if curr.left else None

	return result

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(7)
	root.left.right = Node(6)
	root.right.left = Node(5)
	root.right.right = Node(4)

	print('Preorder: ', preorder(root))

