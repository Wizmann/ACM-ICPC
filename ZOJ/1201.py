#Result: Accepted 	1201 	Python 	20MS 	320KB

import sys

sys.stdin=open("input.txt")
sys.stdout=open("out.txt","w")

def printx(x,n):
	for i in xrange(n):
		if(i==0):print x[i],
		else:sys.stdout.write(' %d' % x[i])
	sys.stdout.write('\n')

def makePer(c,n):
	x=[]
	for i in xrange(n):
		ans=0
		for j in xrange(n):
			if(c[j]>i+1):ans+=1
			elif(c[j]==i+1):
				x.append(ans)
				break
	
	printx(x,n)
	
def makeInv(c,n):
	x=[0 for i in xrange(n)]
	for i in xrange(n):
		ans=0
		j=0
		while(ans<=c[i]):
			if(x[j]==0):ans+=1
			j+=1
		x[j-1]=i+1
	printx(x,n)


while(True):
	n=raw_input()
	while(n==''): n=raw_input()
	n=int(n)
	if(n==0):break
	else:
		while(True):
			cmd=raw_input()
			if(cmd!=''):break
		cmd=cmd.split()
		c=[]
		for i in xrange(n):
			t=int(cmd[i+1])
			c.append(t)
		if(cmd[0]=='P'):
			makePer(c,n)
		else:
			makeInv(c,n)
			

