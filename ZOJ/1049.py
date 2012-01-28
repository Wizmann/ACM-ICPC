#Result: Accepted 	1049 	Python

import sys
import math

sys.stdin=open('input.txt')

pi=3.1415926

n=int(raw_input());
for i in range(n):
	line=sys.stdin.readline();
	a=line.split();
	x=float(a[0])
	y=float(a[1])
	dis=x*x+y*y
	s=0
	r2=0
	year=0
	while(dis>r2):
		s+=100
		r2=s/pi
		year+=1
	print ('Property %d: This property will begin eroding in year %d.' % ((i+1) , year))

print ('END OF OUTPUT.')
