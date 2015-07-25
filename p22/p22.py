def calc_sum(name,alphabet):
	sm = 0
	for c in name:
#		print alphabet.index(c)
		sm = sm + alphabet.index(c) + 1
	return sm


alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
f = open('p022_names.txt', 'r')
str = f.read()
arr = str.split(',')
#print arr

cleant = arr; i = 0;


for name in arr:
	cleant[i] = name.replace('"','').rstrip()
	i = i + 1;

cleant.sort()
scoresum = 0
i = 0

for name in cleant:
	sm = 0
	#print name
	scoresum = scoresum + calc_sum(name,alphabet)*(i + 1)
	#print calc_sum(name, alphabet), i
	i = i + 1

print scoresum
#print cleant
