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
		return not len(self.data)

def spiral_level_order(root):
	result = list()

	if not root:
		return result

	stack1 = Stack()
	stack2 = Stack()
	stack1.push(root)

	while not(stack1.empty() and stack2.empty()):
		while not stack1.empty():
			temp = stack1.pop()
			result.append(temp.key)
			stack2.push(temp.right) if temp.right else None
			stack2.push(temp.left) if temp.left else None

		while not stack2.empty():
			temp = stack2.pop()
			result.append(temp.key)
			stack1.push(temp.left) if temp.left else None
			stack1.push(temp.right) if temp.right else None
	return result

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(7)
	root.left.right = Node(6)
	root.right.left = Node(5)
	root.right.right = Node(4)
	print("Spiral Order traversal of binary tree is ", str(spiral_level_order(root)))
    