from itertools import product

stepDict = dict()

for i in product(range(2), repeat=10):
	for j in range(10):
		stepDict[(i,j)] = 0

copyDict = stepDict.copy()

for key in stepDict.iterkeys():
	if sum(key[0]) == 1 and key[0][0] != 1:
		for i in range(10):
			if key[0][i] == 1 and key[1] == i:
				stepDict[key] = 1

total = 0
i = 1
while i < 40:
	i += 1; print i
	newDict = copyDict.copy()
	for pair in stepDict.iterkeys():
		if pair[1] != 9:
			upTuple = list(pair[0])
			upTuple[pair[1] + 1] = 1
			upTuple = tuple(upTuple)
			upPair = (upTuple, pair[1] + 1)
			newDict[upPair] += stepDict[pair]

		
		if pair[1] != 0:
			downTuple = list(pair[0])
			downTuple[pair[1] - 1] = 1
			downTuple = tuple(downTuple)
			downPair = (downTuple, pair[1] - 1)
			newDict[downPair] += stepDict[pair]
	
		
	for key in newDict.iterkeys():
		if sum(key[0]) == 10:
			total += newDict[key]
	
	stepDict = newDict.copy()
		
print total
