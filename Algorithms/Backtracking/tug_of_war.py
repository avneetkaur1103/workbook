""" Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is
 as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be
  (n-1)/2 and size of other subset must be (n+1)/2."""
import sys

def tug_of_war_util(sol, arr, total_sum, n):
	if len(sol) == n:
		_sum = sum(sol)
		if abs(total_sum/2 - _sum) < tug_of_war_util.min_diff:
			tug_of_war_util.min_diff = total_sum/2 - _sum
			tug_of_war_util.sol = sol[:]
			return

	if len(sol) + len(arr) < n or not arr:
		return

	tug_of_war_util(sol[:], arr[1:], total_sum, n)
	sol.append(arr[0])
	tug_of_war_util(sol, arr[1:], total_sum, n)
	sol.pop()


def tug_of_war(arr):
	total_sum = sum(arr)
	n = len(arr)//2
	sol = list()
	tug_of_war_util.min_diff = sys.maxsize
	tug_of_war_util.sol = list()
	tug_of_war_util(sol, arr, total_sum, n)
	return tug_of_war_util.sol

# Driver Code 
if __name__ == '__main__': 
	arr = [23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4]
	print('Min Value Set: ', tug_of_war(arr))