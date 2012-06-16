#Result:2012-04-18 16:46:38	 Accepted	3609	Python	370	320	Wizmann
import sys

if(__name__=='__main__'):
	n=raw_input()
	n=int(n)
	for i in xrange(n):
		l=raw_input()
		l=l.split()
		a=int(l[0])
		m=int(l[1])
		if(m==1): print 1
		else:
			#print a,m
			ok=False
			for i in xrange(1,m+1):
				if(a*i%m==1):
					print(i)
					ok=True
					break
			if(not ok):
				print"Not Exist"
