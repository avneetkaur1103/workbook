def sherlockAndAnagrams(s):
	n = len(s)
	count = 0
	for l in range(1, n+1):
		all_substring = list()
		for i in range(0, n-l+1):
			j = i + l-1
			lc = [0]*26
			for k in range(i,j+1):
				lc[ord(str[k])-ord('a')] += 1

			for l in all_substring:
				if lc == l:
					count += 1
			all_substring.append(lc)
	return count