from itertools import product
stepDict = dict()

print range(2)

'''
for i in  product('ABCD', repeat=3):
	print i
'''

for i in product(range(2), repeat=10):
	print i
