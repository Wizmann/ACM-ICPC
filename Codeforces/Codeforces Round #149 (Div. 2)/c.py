#Nov 22, 2012 7:16:38 PM	Wizmann	 C - King's Path	 Python	Accepted	 1328 ms	 10200 KB
#coding=utf-8
import sys,re,os
from collections import deque

if(__name__=='__main__'):
	inf=1<<30
	xs,ys,xe,ye=map(int,raw_input().split())
	n=int(raw_input())
	path={}
	for i in xrange(n):
		x,ya,yb=map(int,raw_input().split())
		for y in xrange(ya,yb+1):
			path[(x,y)]=inf
	q=deque([(xs,ys)])
	path[(xs,ys)]=0
	mx=[ 0, 1, 1, 1, 0,-1,-1,-1]
	my=[-1,-1, 0, 1, 1, 1, 0,-1]
	while len(q):
		now=q.popleft()
		step=path[now]
		next=[(now[0]+mx[i],now[1]+my[i]) for i in xrange(len(mx))]
		for item in next:
			if(item in path):
				if step+1<path[item]:
					path[item]=step+1
					q.append(item)
	print path[(xe,ye)] if path[(xe,ye)]<inf else -1

	

