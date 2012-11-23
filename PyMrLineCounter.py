#!/usr/bin/env python
# -*- encoding: utf-8 -*- 
import sys,os

def LineCounter(i_path):
	return open(i_path).read().count('\n')

if(__name__=='__main__'):
	allinall=0
	filesum=0
	for root, dirs, files in os.walk(sys.path[0]):
		for item in files:
			ext=item.split('.')[-1]
			if(ext in ['cc','java','cpp','c','py','cxx','hs','scala','scl']):
				path=root+'/'+item
				if('模版' in path):
					continue
				filesum+=1
				print path
				allinall+=LineCounter(path)
	print "Total problem sloved :",filesum
	print "Total lines of your code :",allinall
