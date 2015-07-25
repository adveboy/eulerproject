import numpy as np

def dif_sets(a,b):
	b = [b]
	m1 = np.tile(b,(len(b[0]),1))
	m2 =  np.tile(np.transpose(b),(1,len(b[0])))
	uq = np.unique(m1+m2)
	return list(set(a).difference(set(uq.flatten())))

#print dif_sets([1,2,3,4],[1,3]) 	

nums = range(1,28123)
abundant = [];
for i in nums:
	pd = [1]
	for j in range(2,i/2+1):
		if (i%j == 0):
			pd = pd + [j]
	if sum(pd) > i:
		abundant = abundant + [i]

num_left = dif_sets(nums,abundant)
print len(num_left)
print sum(num_left)
