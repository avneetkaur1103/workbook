class Stack:

	def __init__(self):
		self.data = list()

	def push(self,val):
		self.data.append(val)

	def pop(self):
		return self.data.pop()

	def __len__(self):
		return len(self.data)

class Queue:

	def __init__(self):
		self.stack1 = Stack()
		self.stack2 = Stack()

	def dequeue(self):
		if not len(self.stack1):
			raise Exception('Empty Queue')
		return self.stack1.pop()

	def enqueue(self, val):
		while len(self.stack1):
			self.stack2.push(self.stack1.pop())

		self.stack1.push(val)

		while len(self.stack2):
			self.stack1.push(self.stack2.pop())

if __name__ == '__main__':
	q = Queue()
	
	for i in range(10):
		q.enqueue(i)

	try:
		print('Dequeued Values ')
		while True:
			print('{}'.format(q.dequeue()), end='\t')
	except Exception as e:
		quit()

