#Result: 2011-06-26 23:13:52 	Accepted 	1048 	Python 	10MS 	320K
import sys

#sys.stdin=open("input.txt","r")

sum=0
for i in range(12):
	m=float(raw_input());
	sum+=m

print ('$%.2lf' % (sum/12))
