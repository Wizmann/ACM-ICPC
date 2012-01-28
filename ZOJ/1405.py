#Accepted 	1405 	Python 	10MS 	320KB 	Wizmann
import sys

if __name__=='__main__':
	sys.stdin=open("input.txt")
	while(True):
		n=sys.stdin.readline()
		n=n.split()
		if(n[0]=='0'):break
		else:
			room=[0 for i in xrange(30)]
			str=n[1]
			n=int(n[0])
			l=len(str)
			leave=0
			for i in xrange(l):
				#print room
				pos=ord(str[i])-ord('A')
				if(n==0 and room[pos]==0):
					leave+=1
					room[pos]=-1
				else:
					if(room[pos]==1):
						n+=1
						room[pos]=0
					elif(room[pos]==0):
						n-=1
						room[pos]=1
			if(not leave): sys.stdout.write("All customers tanned successfully.\n")
			else: sys.stdout.write("%d customer(s) walked away.\n" % leave)
