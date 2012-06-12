import sys

if(__name__=='__main__'):
	instr=raw_input()
	ans=[-1,]
	for ch in instr:
		flag=False
		while(len(ans)>0 and ord(ch)>ans[-1]):
			ans.pop()
		ans.append(ord(ch))
	outstr=''
	for item in ans:
		outstr+=chr(item)
	print outstr
