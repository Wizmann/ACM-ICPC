#Result:2012-04-18 18:02:15	 Accepted	3610	Python	40	320	Wizmann
import sys

if(__name__=='__main__'):
	T=int(raw_input())
	for case in xrange(T):
		l=raw_input()
		l=l.split()
		print l[1],"will survive"
