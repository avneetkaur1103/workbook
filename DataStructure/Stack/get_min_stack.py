class Stack:

	def __init__(self):
		self.data = list()

	def push(self, val):
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

class SpecialStack:

	def __init__(self):
		self.stack = Stack()
		self.min = Stack()

	def push(self, value):
		self.stack.push(value)
		if not len(self.min):
			self.min.push(value)
		else:
			if value <= self.min.top():
				self.min.push(value)

	def pop(self):
		result = self.stack.pop()
		if self.min.top() == result:
			self.min.pop()

		return result

	def get_min(self):
		return self.min.top()

if __name__ == '__main__':
	stack = SpecialStack()

	# for i in range(2,10):
	# 	stack.push(i)

	# for i in range(9, 2, -1):
	# 	print('getMin() = ' + str(stack.get_min()))
	# 	stack.pop()

	stack.push(10)
	stack.push(20)
	stack.push(30)
	print('getMin() = ' + str(stack.get_min()))
	stack.push(5)
	print('getMin() = ' + str(stack.get_min()))

