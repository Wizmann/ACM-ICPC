'''
Result: Apr 24, 2012 1:26:14 PM	Wizmann	 E - Cubes	 Python	Accepted	 730 ms	 16700 KB
'''
import sys

sys.stdin=open('e.txt')

def slove(color,gap,list):
	res=-1
	x=1
	for i in xrange(len(list[color])):
		while(x<len(list[color]) and (list[color][x]-list[color][i]+1)-(x-i+1)<=gap):
			x+=1
		res=max(res,x-i)
	return res


if(__name__=='__main__'):
	
	instr=raw_input()
	instr=instr.split()
	n=int(instr[0]);m=int(instr[1]);k=int(instr[2]);
	l=[ [] for i in xrange(m+1)]
	
	instr=raw_input()
	instr=instr.split()
	for i in xrange(len(instr)):
		instr[i]=int(instr[i])
		l[instr[i]].append(i)
	
	ans=0
	for i in xrange(1,m+1):
		ans=max(ans,slove(i,k,l))
	print ans
