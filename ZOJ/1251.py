#Result: Accepted 	1251 	Python 	10MS 	320KB 	Wizmann
import sys

sys.stdin=open('input.txt')

cas=1
while(True):
	n=''
	while(n==''):
		n=raw_input()
	n=int(n)
	if(n==0):break
	else:
		l=sys.stdin.readline()
		l=l.split()
		sum=0
		for i in xrange(n):
			l[i]=int(l[i])
			sum+=l[i]
		sum/=n
		ans=0
		for i in xrange(n):
			if(l[i]>sum): ans+=l[i]-sum
		
		print 'Set #%d' % cas
		cas+=1
		print 'The minimum number of moves is %d.' % ans
		print ''
