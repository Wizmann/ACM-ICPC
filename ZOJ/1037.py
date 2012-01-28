#Result: 2011-06-26 11:15:29 	Accepted 	1037 	Python 	210MS 	452K	Wizmann
import sys
import math

n=int(raw_input());

for i in xrange(n):
	print 'Scenario #%d:' % (i+1)
	line=sys.stdin.readline();
	a=line.split()
	x=int(a[0])
	y=int(a[1])
	if(x%2 and y%2):
		print '%.2lf' % (x*y-1+math.sqrt(2))
	else:
		print '%.2lf' % (x*y)
	print ''
	
