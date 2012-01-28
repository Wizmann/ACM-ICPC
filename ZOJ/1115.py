#Result: Accepted 	1115 	Python 	10MS 	320KB
import sys

while(True):
	n=int(raw_input())
	if(n==0): break
	else:
		if(n%9==0): print '9'
		else: print n%9
