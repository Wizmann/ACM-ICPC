import sys

#sys.stdin=open("input.txt");
#sys.stdout=open("out.txt","w");
#2561363 	2011-06-22 18:42:04 	Accepted 	1099 	Python 	10 	320 	Wizmann


#在你同时关注语言和算法的时候，你是写不好程序的。。。

l=0;
hr=1;
for line in sys.stdin:
	str=line.split()

	for item in str:
		if item=='<hr>':
			if hr==0:
				print '\n' + '-' * 80
				hr=1
				l=0;
			else:
				print '-' * 80
				l=0
		else:
			if l+len(item)>80:
				sys.stdout.write('\n'+item)
				l=len(item)+1
				hr=0;
			elif item=='<br>':
				hr=1
				print ''
				l=0
			else:
				if(hr==1): sys.stdout.write(item)
				else: sys.stdout.write(' '+item)
				l+=len(item)+1
				hr=0;
