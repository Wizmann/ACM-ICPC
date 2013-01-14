#Jan 9, 2013 8:35:25 AM	Wizmann	 D - Black and White Tree	 Python	Accepted	811 ms	19576 KB
#coding=utf-8
import sys,re,os

if(__name__=='__main__'):
	n=int(raw_input())
	black,white=[],[]
	for i in xrange(n):
		color,value=map(int,raw_input().split())
		node={'value':value,'nr':i+1}
		if color==1: black.append(node)
		else: white.append(node)
	
	i,j=0,0
	lb,lw=len(black),len(white)
	while i<lb and j<lw:
		print black[i]['nr'],white[j]['nr'],min(black[i]['value'],white[j]['value'])
		if black[i]['value']<white[j]['value']:
			white[j]['value']-=black[i]['value']
			i+=1
		else:
			black[i]['value']-=white[j]['value']
			j+=1
	while i+1<lb:
		i+=1
		print black[i]['nr'],white[lw-1]['nr'],0
	while j+1<lw:
		j+=1
		print white[i]['nr'],black[lb-1]['nr'],0
		
