//Result:Accepted	1151	Python	170	320	Wizmann
import sys

sys.stdin=open('input.txt')

t=int(raw_input())
while(t>0):
	t-=1
	n=raw_input()
	while(n==''):
		n=raw_input()
	n=int(n)
	while(n>0):
		n-=1
		s=sys.stdin.readline()
		s=s.split()
		flag=1
		for item in s:
			if(not flag):
				print ' ',
			sys.stdout.write('%s' % item[::-1])
			flag=0
		print ''
	if(t!=0): print ''
