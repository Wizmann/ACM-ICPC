#2011-09-14 21:27:07 	Accepted 	2001 	Python 	290 	320 	Wizmann

import sys

def rev(x):
	t=0
	while x>0:
		t=t*10+x%10
		x/=10
	return t

if __name__ == '__main__':
	n=int(raw_input())
	for i in xrange(n):
		l=raw_input()
		l=l.split()
		a=int(l[0])
		b=int(l[1])
		a=rev(a)
		b=rev(b)
		print rev(a+b)
