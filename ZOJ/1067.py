//Result:Accepted	1067	Python	10	320	Wizmann
import sys

class color(object):
	def __init__(self,l):
		self.c=[0,0,0]
		for i in xrange(3):
			self.c[i]=int(l[i])
	
	def setcolor(self,l):
		for i in xrange(3):
			self.c[i]=int(l[i])
			
	def printcolor(self):
		sys.stdout.write("(%d,%d,%d)\n" % (self.c[0],self.c[1],self.c[2]))
	
	def count(self,l):
		ans=0
		for i in xrange(3):
			ans+=(self.c[i]-int(l[i]))**2
		return ans

def quit(l):
	ans=0
	for i in xrange(3):
		ans+=int(l[i])
	if(ans==-3): return True
	else: return False

#sys.stdin=open('input.txt')

c=[]
for i in xrange(16):
	a=sys.stdin.readline()
	a=a.split()
	t=color(a);
	#t.printcolor()
	c.append(t)

while(True):
	a=sys.stdin.readline()
	a=a.split()
	if(quit(a)): break
	else:
		pad=-1
		low=1<<20
		for i in xrange(16):
			if(c[i].count(a)<low):
				pad=i
				low=c[i].count(a)
		sys.stdout.write("(%s,%s,%s) maps to " % (a[0],a[1],a[2]))
		c[pad].printcolor()
	
