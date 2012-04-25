#Result:Apr 25, 2012 5:09:26 PM	Wizmann	 B - Divisibility Rules	 Python	Accepted	 140 ms	 3700 KB
import sys
from random import randint
from math import sqrt

mul=[]
rand=[]
SIZE = 32

def checkTypeZwei(base,div):
	for i in xrange(SIZE):
		if(int(mul[i])%div==0):
			return i
	return -1

def checkTypeDrei(base,div):
	for num in rand:
		sum=0
		for ch in num:
			sum+=ch
		if(sum%div!=0):
			#print sum,div
			return False

	return True

def checkTypeElf(base,div):
	for i in xrange(SIZE):
		num=rand[i]
		eve=0
		odd=0
		ind=0
		num=num[::-1]
		for ch in num:
			if(ind&1):
				odd+=ch
			else:
				eve+=ch
			ind+=1

		if(odd!=eve and abs(odd-eve)%div!=0 ):
			return False
	
	return True


def checkTypeSechs(base,div):
	factor=[]
	for i in xrange(2,div+1):
		if(div%i==0):
			factor.append(i)
			while(div%i==0):
				div/=i
	ans=True
	#print factor
	if(len(factor)<2):
		return False
	for num in factor:
		if(checkTypeZwei(base,num)!=-1 or checkTypeDrei(base,num) or checkTypeElf(base,num)):
			ans=True
		else:
			ans=False
			break;
	return ans


def xBase(num,base):
	res=[]
	while(num):
		tmpNum=num%base
		tmpList=[]
		tmpList.append(tmpNum)
		tmpList.extend(res)
		res=tmpList
		num/=base
	return [0] if(res=='') else res

if(__name__=='__main__'):
	

	instr=raw_input()
	instr=instr.split()
	base=int(instr[0])
	div=int(instr[1])
	
	for i in xrange(SIZE):
		mul.append(str(base**i))

	for i in xrange(SIZE):
		num=randint(0,1<<16)
		num*=div
		#print xBase(num,base)
		rand.append(xBase(num,base))
	type=7
	leng=-1
	if(type==7):
		leng=checkTypeZwei(base,div)
		if(leng!=-1):
			type=2
	
	if(type==7):
		if(checkTypeDrei(base,div)):
			type=3
	
	if(type==7):
		if(checkTypeElf(base,div)):
			type=11
	
	if(type==7):
		if(checkTypeSechs(base,div)):
			type=6

	print(str(type)+'-type')
	if(type==2):
		print leng
