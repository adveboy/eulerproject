#------------------------------------
#Project Euler Problem 65
n0, n1, L = 1, 2, 5
for i in range(2, L): 
	print "n0 =", n0, "n1 =" , n1
	n1, n0 = n0, n1 + n0 * (1 if i % 3 else 2 * i//3)
print L, "th nominator convergent for e =", str(n0)
print L, "convergent for e =", sum(map(int, str(n0)))
#------------------------------------

#------------------------------------

#------------------------------------

#------------------------------------