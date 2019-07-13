""" Inorder traversal with stack """
class Node(object):
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
		return len(self.data) == 0

def inorder(root):
	stack = Stack()
	# stack.push(root)
	curr = root
	while curr or stack: # with current we dissect the call stack in 2, 1 current call cell and rest stacked up
		while curr:
			stack.push(curr) if curr else None
			curr = curr.left
		curr = stack.pop()
		print(curr.key, end=' ')
		# stack.push(curr.right) if curr.right else None
		curr = curr.right

if __name__ == '__main__':
	root = Node(1) 
	root.left = Node(2) 
	root.right = Node(3) 
	root.left.left = Node(4) 
	root.left.right = Node(5) 
	inorder(root)



