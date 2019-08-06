""" Implement max heap """
class MaxHeap:
	def __init__(self):
		self.heap = []

	@staticmethod
	def parent(i):
		return (i-1) // 2

	def left(self, i):
		if 2*i + 1 < len(self.heap):
			return 2*i + 1
		return None

	def right(self, i):
		if 2*i + 2 < len(self.heap):
			return 2*i + 2
		return None

	def heapify(self, index):
		largest = index
		left = self.left(index)
		right = self.right(index)

		if left and self.heap[left] > self.heap[largest]:
			largest = left

		if right and self.heap[right] > self.heap[largest]:
			largest = right

		if not largest == index:
			self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
			self.heapify(largest)

	def shift_up(self, index):
		while not index == 0:
			parent = self.parent(index)
			if self.heap[index] > self.heap[parent]:
				self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
				index = parent

	def push(self, key):
		self.heap.append(key)
		self.shift_up(len(self.heap)-1)

	def pop(self):
		result = self.heap[0]
		if self.size() > 1:
			self.heap[0] = self.heap.pop()
			self.heapify(0)
		return result

	def get_max(self):
		return self.heap[0]

	def print(self):
		print(self.heap)

	def size(self):
		return len(self.heap)

if __name__ == '__main__':
	mh = MaxHeap()
	for i in range(11):
		mh.push(i)
	mh.print()
	arr = [mh.pop() for _ in range(mh.size())]
	print('Arr: ', arr)


