#Sep 10, 2011 1:36:14 PM 	Wizmann 	A - Cifera 	Python 	Accepted 	60 ms 	2800 KB 

import sys
from math import log10
from math import pow

if __name__=='__main__':
	eps=1e-8
	a=float(raw_input())
	b=float(raw_input())
	c=int(log10(b)/log10(a)+eps)
	if pow(a,c)==b:
		print "YES"
		print int(c+eps)-1
	else:
		print "NO"
