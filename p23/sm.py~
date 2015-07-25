import numpy as np

def dif_sets(a,b):
	b = [b]
	m1 = np.tile(b,(len(b[0]),1))
	m2 =  np.tile(np.transpose(b),(1,len(b[0])))
	uq = np.unique(m1+m2)
	print uq
	return list(set(a).difference(set(uq.flatten())))

print dif_sets([1,2,3,4],[1,3])	
