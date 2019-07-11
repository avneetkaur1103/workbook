'''
	Variation of sorting a stack without for/while.
	We store the elements in function call stacks > pop it there to empty stack at the end (to set up empty base inverient)
	and fill it at required place while rewinding.
'''

class Stack:

	def __init__(self):
		self.data = list()

	def push(self,val):
		self.data.append(val)

	def extend(self, list):
		for i in list:
			self.push(i)

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

	def __str__(self):
		return str(self.data)
			

def sorted_insert(stack, value):
	if stack.empty() or stack.top() < value:
		stack.push(value)
		return

	temp_val = stack.pop()
	sorted_insert(stack,value)
	stack.push(temp_val)

def sort_stack(stack):

	if stack.empty():
		return

	value = stack.pop()
	sort_stack(stack)
	sorted_insert(stack, value)

if __name__ == '__main__':
	stack = Stack()
	stack.extend([30,-5,18,14,-3])
	sort_stack(stack)
	print('Sorted stack = ' + str(stack))



