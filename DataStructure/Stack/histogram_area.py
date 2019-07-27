'''
	Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
	For simplicity, assume that all bars have same width and the width is 1 unit.
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

def max_area_histogram(input):

	stack = Stack()
	max_area = 0

	for index, value in enumerate(input):
		if stack.empty() or input[stack.top()] <= value:
			stack.push(index)
		else:
			while input[stack.top()] > value:
				area = (index - stack.top() - 1) * input[stack.top()]
				stack.pop()
				max_area = max(area,max_area)
			stack.push(index)

		




if __name__ == '__main__':
	# Driver Code 
	hist = [6, 2, 5, 4, 5, 1, 6] 
	print("Maximum area is",  
       max_area_histogram(hist)) 