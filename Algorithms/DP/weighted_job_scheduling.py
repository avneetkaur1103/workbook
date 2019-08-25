"""Given N jobs where every job is represented by following three elements of it.
Start Time, Finish Time, Profit or Value Associated (>= 0)
Find the maximum profit subset of jobs such that no two jobs in the subset overlap."""
from collections import namedtuple
Job = namedtuple('Job', 'start finish profit')

def max_profit(jobs):
	n = len(jobs)
	dp = [0 for _ in range(n)]
	jobs.sort(key=lambda elem: elem[1])
	dp[0] = jobs[0].profit
	
	for i in range(1, n):
		dp[i] = jobs[i].profit
		for j in range(i-1, -1, -1):
			if jobs[j].finish <= jobs[i].start:
				dp[i] += dp[j]
				break
	return max(dp)


if __name__ == '__main__':
	jobs = [Job(3, 10, 20), Job(1, 2, 50), Job(6, 19, 100), Job(2, 100, 200)];
	print('Max Profit: ', max_profit(jobs))