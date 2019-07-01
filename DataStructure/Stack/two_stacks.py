class TwoStacks:

	def __init__(self, size):
		self.size = size
		self.data = [None] * size
		self.top1 = -1
		self.top2 = size

	def push_1(self, value):
		if self.top1 < self.top2 - 1 :
			self.top1 += 1
			self.data[self.top1] = value
		else:
			raise Exception('Stack1: Stack Overflow')

	def push_2(self, value):
	 	if self.top1 < self.top2 - 1:
	 		self.top2 -= 1
	 		self.data[self.top2] = value
	 	else:
	 		raise Exception('Stack2: Stack Overflow')

	def pop_1(self):
	 	if not self.top1 == -1:
	 		result = self.data[self.top1]
	 		self.top1 -= 1
	 		return result
	 	else:
	 		raise Exception('Stack1 : Stack Underflow')

	def pop_2(self):
	 	if not self.top2 == self.size:
	 		result = self.data[self.top2]
	 		self.top2 += 1
	 		return result
	 	else:
	 		raise Exception('Stack2 : Stack Underflow')

if __name__ == '__main__':
	two_stack = TwoStacks(20)

	for i in range(1,6):
		two_stack.push_1(i)
	for i in range(20,14,-1):
		two_stack.push_2(i)

	print(two_stack.pop_1())
	print(two_stack.pop_2())
	print(two_stack.pop_1())
	print(two_stack.pop_2())


