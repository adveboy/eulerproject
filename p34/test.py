import math
def P(n):
	return (1 - n + math.pow(n, 2) - math.pow(n, 3) + math.pow(n, 4) - math.pow(n, 5) + math.pow(n, 6) - math.pow(n, 7) + math.pow(n, 8) - math.pow(n, 9) + math.pow(n, 10))
	
for i in range(2,10):
	print P(i)
