''' Implement LRU Cache '''
from collections import deque

class LRUCache:
	def __init__(self, size):
		if size <= 0:
			raise Exception('Only positive integer as size is allowed')
		self.dq = deque(maxlen=size)
		self.lookup_table = dict()
		self.size = size

	def refer(self, key):
		ref = self.lookup_table.get(key)
		if ref:
			self.dq.remove(key)
			self.lookup_table.pop(key)

		else:
			if len(self.dq) == self.size:
				self.dq.popleft()

		self.dq.append(key)
		self.lookup_table[key] = self.dq[-1]


	def __str__(self):
		return str(self.dq)


if __name__ == '__main__':
	cache = LRUCache(4)
	cache.refer(1)
	cache.refer(2)
	cache.refer(3)
	cache.refer(1)
	cache.refer(4)
	cache.refer(5)
	print('Cache containts: ' + str(cache))


