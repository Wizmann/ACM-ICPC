#Jan 8, 2013 5:38:49 PM	Wizmann	 C - Balls and Boxes	 Python	Accepted	296 ms	7964 KB
#coding=utf-8
import sys,re,os,json,math

if(__name__=='__main__'):
	n,x=map(int,raw_input().split())
	x-=1
	a=map(int,raw_input().split())
	mini=min(a)
	a=map(lambda y:y-(mini-1),a)
	s=(mini-1)*n
	while(a[x]>0):
		a[x]-=1
		s+=1
		x=(x-1+n)%n
	a[x]=s
	print ' '.join(map(str,a))
