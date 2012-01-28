#Result: Accepted 	1240 	Python 	10MS 	320KB 	Wizmann

import sys

sys.stdin=open('input.txt')

n=int(raw_input())
for cas in xrange(n):
	print 'String #%d' % (cas+1)
	s=sys.stdin.readline()
	l=len(s)
	for i in xrange(l-1):
		t=ord(s[i])
		x=''
		if(t+1>ord('Z')): x='A'
		else: x=chr(t+1)
		sys.stdout.write(x)
	sys.stdout.write('\n\n')
