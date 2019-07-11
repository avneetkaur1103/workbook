'''
	Given an array, for each element find the value of nearest element to the right which is having frequency greater than as that of current element.
	If there does not exist an answer for a position, then make the value ‘-1’.
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

from collections import Counter

def ngf(input):
	fq_map = Counter(input)
	print(fq_map)

	stack = Stack()
	result = [None] * len(input)
	for index, value in enumerate(input):

		if stack.empty() or ((not stack.empty()) and fq_map.get(input[stack.top()]) >= fq_map.get(value)):
			stack.push(index)

		else:
			while fq_map.get(input[stack.top()]) < fq_map.get(value):
				i = stack.pop()
				result[i] = value
				stack.push(index)

	while not stack.empty():
		result[stack.pop()] = -1

	return result

if __name__ == '__main__':
	print('Ans = '+ str(ngf([1,1,2,3,4,2,1])))