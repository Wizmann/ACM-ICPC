#Sep 10, 2011 2:24:59 PM 	Wizmann 	B - PFAST Inc. 	Python 	Accepted 	230 ms 	2800 KB 

import sys

#sys.stdin=open("b.txt")

def binman(num,n):
	if num & (1<<n): return True
	else: return False

def work(num,dislike):
	for item in dislike:
		if binman(num,item[0]) and binman(num,item[1]): return False
	return True
def sum(n):
	ans=0
	while n>0:
		if n & 1: ans+=1
		n>>=1
	return ans

def printlist(i,name):
	pad=0
	out=[]
	while i>0:
		if i & 1: out.append(name[pad])
		pad+=1
		i>>=1
	out.sort()
	for item in out:
		print item

if __name__=='__main__':
	l=raw_input()
	l=l.split()
	dict={}
	name=[]
	dislike=[]
	n=int(l[0])
	ask=int(l[1])
	for i in xrange(n):
		t=raw_input()
		dict[t]=i
		name.append(t)
	for i in xrange(ask):
		t=raw_input()
		t=t.split()
		for i in xrange(len(t)):
			t[i]=dict[t[i]]
		dislike.append(t)
	ans=0
	list=0
	
	for i in xrange(1<<n):
		if work(i,dislike):
			t=sum(i)
			if(t>ans):
				list=i
				ans=t
	
	print ans
	printlist(list,name)
	
		
