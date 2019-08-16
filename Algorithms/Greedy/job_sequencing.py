""" Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline.
 It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. 
 How to maximize total profit if only one job can be scheduled at a time. """
import operator

def schedule(arr, n_slots):
	arr = sorted(arr, key=operator.itemgetter(2), reverse=True)
	result = list()
	slots = [True] * n_slots
	for id, deadline, profit in arr:
		for i in range(deadline-1, -1, -1):
			if slots[i]:
				result.append((id, i+1, profit))
				slots[i] = False
				break

	print('Result ', result)

# Driver COde 
arr = [['a', 2, 100],  # Job Array
       ['b', 1, 19], 
       ['c', 2, 27], 
       ['d', 1, 25], 
       ['e', 3, 15]] 
  
  
print("Following is maximum profit sequence of jobs") 
schedule(arr, 3)