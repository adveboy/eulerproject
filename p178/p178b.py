from metaprogramming import *

@memorized
def stepreversed(current, length, used):
	if length == 0:
		if used == (True, True, True, True, True,
			    True, True, True, True, True):
			return 1
		return 0
	cnt = 0
	if current < 2: #change to 9
		used2 = list(used)
		used2[current+1] = True
		cnt += stepreversed(current+1, length-1, tuple(used2))
	if current > 0:
		used3 = list(used)
		used3[current-1] = True
		cnt += stepreversed(current-1, length-1, tuple(used3))
	return cnt

def euler178(length):
	a0 = stepreversed(0, length, (True, False, False, False, False, False, False, False, False, False))
	a1 = stepreversed(1, length, (False, True, False, False, False, False, False, False, False, False))
	a2 = stepreversed(2, length, (False, False, True, False, False, False, False, False, False, False))
	a3 = stepreversed(3, length, (False, False, False, True, False, False, False, False, False, False))
	a4 = stepreversed(4, length, (False, False, False, False, True, False, False, False, False, False))
	return (a0+a1+a2+a3+a4)*2-a0

print sum([euler178(x) for x in xrange(5)])