from time import time
start=time()
a=[0,31,28,31,30,31,30,31,31,30,31,30,31]
d,m,y=1,1,1901
day=2
count=0
while y!=2001:
    if day==0:
        count+=1
    if m==2 and y%4==0 and y!=2000:
        a[2]=29
    day=(day+a[m])%7
    a[2]=28
    m+=1
    if m==13:
        m=1
        y+=1


print count
print "time   ", time()-start