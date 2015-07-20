n0, n1, L = 1, 2, 10
a = [1] + [2] * 7
n0, n1 = 1, a[len(a) - 1]

for i in range(len(a)-2,1,-1): 
	print "n0 =", n0, "n1 =" , n1
	n0, n1 = n1, a[i]*n0 + 1
	n1, n0 = n0, n1 + n0 * (1 if i % 3 else 2 * i//3)

n0 = a[0]*n1 + n0
print n0
#print L, "n0 =", n0
# print L, "convergent for e =", sum(map(int, str(n0)))