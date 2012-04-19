#Result:2012-04-19 14:42:45	 Accepted	3603	Python	460	320	Wizmann
import sys

if(__name__=='__main__'):
	#sys.stdin=open("input.txt")
	CASE=int(raw_input())
	for case in xrange(CASE):
		
		n=int(raw_input())
		g=[ [0 for i in xrange(n)] for j in xrange(30)]
		for i in xrange(n):
			s=raw_input()
			for char in s:
				g[ord(char)-ord('A')][i]+=1

		
		for i in xrange(26):
			num=min(g[i])
			for j in xrange(num):
				sys.stdout.write("%c" % chr(i+ord('A')))

		sys.stdout.write("\n")

