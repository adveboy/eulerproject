def cycle_length(k):
	rn = 1
	rnlist = []
	clist = []
	while True:
		rn = (rn*10)%k
		c = rn*10 - rn*k
		if rn == 0: 
			return 0
		if c in clist:
			if (rnlist[clist.index(c)] == rn):
				return len(clist) - clist.index(c)
		else:
			rnlist = rnlist + [rn]
			clist = clist + [c]
	return -1

mx = 0
pos = 0
for i in range(1,1000):
	curr = cycle_length(i)
	if (curr > mx):
		pos = i
		mx = curr

print pos

