import sys;

if(__name__=='__main__'):
	l=raw_input();
	l=l.split()
	a=int(l[0])
	b=int(l[1])
	c=[]
	while(a or b):
		c.append( (b%3-a%3)%3 )
		if(c[len(c)-1]<0):
			c[len(c)-1]+=3
		a/=3
		b/=3

	ans=0
	mul=1;
	sz=len(c)
	#print(c)
	for i in xrange(sz):
		ans+=c[i]*mul
		mul*=3
	print(ans)
	
