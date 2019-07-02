''' This problem is an extension of next greater element problem.
	Can be thought of as a problem finding next greater price on the left.
	It will be good to start from back if we looking NGE on the right.
'''

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

def calculate_span(prices):

	if not len(prices):
		return None

	result = list()
	stack = Stack()
	result.append(1) # First Stock
	stack.push(0)    #index 1st element 

	for i in range(1, len(prices)):

		price = prices[i]
		while not stack.empty() and price > prices[stack.top()]:
			stack.pop()

		result.append(i+1 if stack.empty() else i - stack.top())
		stack.push(i)

	return result

if __name__ == '__main__':
	prices = [10, 4, 5, 90, 120, 80] 
	print('Ans = '+ str(calculate_span(prices)))




