""" Iterative Postorder Traversal. 
	Implementation: postorder => reverse{/stackentry}(right to left preorder) 
 """

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

	def __next__(self):
		if self.empty():
			raise StopIteration
		else:
			return self.pop()

	def __iter__(self):
		return self

def postorder(root):
	stack = Stack()
	reverse_store = Stack()
	stack.push(root)

	while not stack.empty():
		curr = stack.pop()
		reverse_store.push(curr.key)
		stack.push(curr.left) if curr.left else None
		stack.push(curr.right) if curr.right else None

	return reverse_store

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(7)
	root.left.right = Node(6)
	root.right.left = Node(5)
	root.right.right = Node(4)

	print('Preorder: ', list(postorder(root)))


