import sys,os

def gcd(a,b):
	if(a<b):
		return gcd(b,a)
	else:
		if(a%b==0): return b
		else:
			return gcd(b,a%b)

if(__name__=='__main__'):
	instr=raw_input().split()
	n=int(instr[0])
	m=int(instr[1])
	nlist=[int(item) for item in raw_input().split()]
	mlist=[int(item) for item in raw_input().split()]
	
	for i in xrange(n):
		if(len(nlist)==0 or nlist[0]!=0):
			break
		else:
			del nlist[0]
			n-=1
	for i in xrange(m):
		if(len(mlist)==0 or mlist[0]!=0):
			break
		else:
			del mlist[0]
			m-=1
	if(n==0 and len(nlist)>0): upper=nlist[0]
	else: upper=0
	if(m==0 and len(mlist)>0): lower=mlist[0]
	else: lower=0 
	if(m==n and m!=0 and n!=0):
		upper=nlist[0]
		lower=mlist[0]
		t=(upper*lower)/abs(upper*lower)
		t_gcd=gcd(abs(upper),abs(lower))
		upper/=t_gcd
		lower/=t_gcd
		upper=t*abs(upper)
		lower=abs(lower)
		print '%d/%d' % (upper,lower)
	else:
		if(n>m):
			t=(nlist[0]*mlist[0])/abs(nlist[0]*mlist[0])
			if(t<0): print '-Infinity'
			else: print 'Infinity'
		else:
			print '0/1'
	
