#Nov 6, 2012 4:44:07 AM	Wizmann	 A - Two Bags of Potatoes	 Python	Accepted	125 ms	6376 KB
import sys,re,os
for lines in sys.stdin:
	y,k,n=[int(x) for x in lines.split()]
	ans=[x_y-y for x_y in xrange(0,n+1,k) if x_y>y]
	print ' '.join(map(str,ans)) if len(ans)>0 else -1
