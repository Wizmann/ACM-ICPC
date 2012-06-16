#2012-06-16 04:20:19	Moody Wizmann	Adding Reversed Numbers	 accepted	0.54	3.7M	PYTH 2.5
T=int(raw_input())
for cas in xrange(T):
	inlist=[int(item[::-1]) for item in raw_input().split()]
	print int(str(sum(inlist))[::-1])
