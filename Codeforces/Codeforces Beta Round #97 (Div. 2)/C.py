import sys;

if(__name__=='__main__'):
	n=int(raw_input())
	l=raw_input()
	l=l.split()
	for i in xrange(n):
		l[i]=int(l[i])
	
	l.sort()
	if l[n-1]==1:
		l[n-1]=2
	else:
		l[n-1]=1
	l.sort()
	print l[0],
	for i in xrange(n-1):
		print "%d" % l[i+1],
