""" Design a Data Structure for the following operations.
 The data structure should be efficient enough to accommodate the operations according to their frequency."""
import heapq
class Data:
	def __init__(self, key):
		self.key = key

	def __hash__(self):
		return hash(self.key)

	def __lt__(self, other):
		return self.key < other.key

class DS:
	def __init__(self):
		self.values = dict()
		self.min_vals = []
		self.max_vals = []

	def push(self, key):
		d = Data(key)
		self.values[d] = d 
		heapq.heappush(self.min_vals, d)
		heapq.heappush(self.max_vals, d)
		heapq._heapify_max(self.max_vals)

	def pop(self, key):
		d = self.values.get(key, None)

		indx = self.min_vals.index(d)
		self.min_vals[indx] = self.min_vals[-1]
		self.min_vals.pop()
		if indx < len(self.min_vals):
			heapq._siftup(self.min_vals, indx)
			heapq._siftdown(self.min_vals, 0, indx)

		indx = self.max_vals.index(d)
		self.max_vals[indx] = self.max_vals[-1]
		self.max_vals.pop()
		if indx < len(self.max_vals):
			heapq._siftup_max(self.max_vals, indx)
			heapq._siftdown_max(self.max_vals, 0, indx)

		self.values.pop(d)

	def get_min(self):
		return self.min_vals[0].key

	def get_max(self):
		return self.max_vals[0].key

	def delete_min(self):
		d = heapq.heappop(self.min_vals)

		indx = self.max_vals.index(d)
		self.max_vals[indx] = self.max_vals[-1]
		self.max_vals.pop()
		if indx < len(self.max_vals):
			heapq._siftup_max(self.max_vals, indx)
			heapq._siftdown_max(self.max_vals, 0, indx)

		self.values.pop(d)

	def delete_max(self):
		d = heapq._heappop_max(self.max_vals)

		indx = self.min_vals.index(d)
		self.min_vals[indx] = self.min_vals[-1]
		self.min_vals.pop()
		if indx < len(self.min_vals):
			heapq._siftup(self.min_vals, indx)
			heapq._siftdown(self.min_vals, 0, indx)

		self.values.pop(d)

if __name__ == '__main__':
	ds = DS()
	ds.push(10)
	ds.push(20)
	ds.push(30)
	ds.push(40)
	ds.push(50)

	print('Min: ', ds.get_min())
	print('Max: ', ds.get_max())
	ds.delete_max()
	ds.delete_min()
	ds.push(-5)
	print('Min: ', ds.get_min())
	print('Max: ', ds.get_max())







