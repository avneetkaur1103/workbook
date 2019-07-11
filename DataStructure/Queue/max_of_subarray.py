''' Given an array and an integer K, find the maximum for each and every contiguous subarray of size k. '''

def k_subarray_max(input, k):
	from collections import deque
	dq = deque(maxlen=k)
	result = list()
	for i in range(k):
		while dq and input[dq[-1]] <= input[i]:
			dq.pop()
		dq.append(i)

	for i in range(k,len(input)):
		result.append(input[dq[0]])

		while dq and dq[0] <= i-k:
			val = dq.popleft()
			# Debug: print('removing ' + str(input[val]) + ' for i = ' + str(i))

		while dq and input[dq[-1]] <= input[i]:
			dq.pop()
		dq.append(i)

	result.append(input[dq.popleft()])
	return result

if __name__ == '__main__':
	result = k_subarray_max([ 12, 1, 78, 90, 57, 89, 56 ],3)
	print('Ans: ' + str(result))

