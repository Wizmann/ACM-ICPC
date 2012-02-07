#Sep 10, 2011 3:24:33 PM 	Wizmann 	C - Grammar Lessons 	Python 	Accepted 	60 ms 	3000 KB 

import sys
#sys.stdin=open('c.txt')


male=['lios','etr','initis']
female=['liala','etra','inites']

def endwith():
	print 'NO'
	exit(0)

if __name__=='__main__':
	list=raw_input()
	list=list.split()
	m=f=0
	for i in xrange(len(list)):
		if not( m and f ):
			flag=False
			for j in xrange(len(male)):
				if list[i].endswith(male[j]):
					m+=1
					list[i]=j+1
					flag=True
					break
			if not flag:
				for j in xrange(len(female)):
					if list[i].endswith(female[j]):
						f+=1
						list[i]=j+1
						flag=True
						break
			if not flag:
				endwith()
		else: break
	if m and f:
		endwith()
	
	#status 0->init 1->adj 2->noun 3->verb
	status=0
	if(len(list)==1):
		print 'YES'
		exit(0)
	for item in list:
		if status == 0:
			if(item==1 or item==2): status=item
			else:endwith()
		elif status == 1:
			if(item==1 or item==2): status=item
			else:endwith()
		elif status == 2:
			if(item == 1 or item ==2):endwith()
			else:status=item
		elif status == 3:
			if(item != 3):endwith()
	if status == 1:endwith()	
	print 'YES'
				
			
