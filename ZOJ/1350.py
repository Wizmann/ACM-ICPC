#Result:2011-08-01 23:05:13 	Accepted 	1350 	Python 	40MS 	320KB 	Wizmann
import sys

sys.stdin=open('input.txt')

t=int(raw_input())

while(t>0):
	n=int(raw_input())
	t-=1
	l=[1 for i in xrange(n+1)]
	for i in xrange(n):
		j=i+1
		while(j<=n):
			l[j]=not l[j]
			j+=(i+1)
	
	ans=0
	for i in xrange(n):
		if(l[i+1]==0): ans+=1
		
	print ans
