#Accepted 	1796 	Python 	10MS 	320KB 	Wizmann
import sys

sys.stdin=open('input.txt')

while(True):
	l=sys.stdin.readline()
	l=l.split()
	n=len(l)
	zero=0
	for i in xrange(n):
		l[i]=int(l[i])
		if(l[i]==0): zero+=1
	if(zero==6):break
	a=-l[0]+l[3]+l[5]
	b=-l[1]+l[2]+l[4]
	print("Anna's won-loss record is %d-%d." %(a,b))
