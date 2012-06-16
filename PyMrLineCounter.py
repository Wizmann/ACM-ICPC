#!/usr/bin/env python
# -*- encoding: utf-8 -*- 
import sys,os

def LineCounter(i_path):
	res=0
	f=open(i_path)
	for lines in f:
		res+=1
	return res

if(__name__=='__main__'):
	allinall=0
	for root, dirs, files in os.walk(sys.path[0]):
		for item in files:
			ext=item.split('.')
			ext=ext[-1]
			if(ext in ['cc','java','cpp','c','py','cxx']):
				path=root+'/'+item
				print path
				allinall+=LineCounter(path)
	print "Total lines of your code :",allinall
