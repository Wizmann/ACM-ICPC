# -*- coding: utf-8 -*-
import sys

if(__name__=='__main__'):
	poker=raw_input()
	n0=0;n1=0;
	L=len(poker)
	for i in xrange(L):
		if(poker[i]=='1'):
			n1+=1
		elif(poker[i]=='0'):
			n0+=1
	x=L-n0-n1
	
	'''
	Masha's aim is to minimize the number and Petya's aim is to maximize it.
	Masha moves first.
	
	所以Masha每次优先取1，有1必取，每次游戏取(L-1)/2次
		=>if(n1<=(L-1)/2): print("00")
	Petya每次优先取高位0，每次游戏取(L-2)/2次
		=>if(n0<=(L-2)/2): print("11")
	
	考虑到有'?'的情况，所以在n0<=L/2 and L/2<=n0+x 的临界情况下
	if(poker[L-1]=='1' or (poker[L-1]=='?' and n1+1 <= (L+1)/2)): print("01")
	即poker最后一位为1或者poker[L-1]最后一位为'?'而且n1个数小于一半的时候，print("01")
	if(poker[L-1]=='0' or (poker[L-1]=='?' and n0+1 <= L/2)): print("10") 
	基本同上
	'''
	
	if(n1<=(L-1)/2): #如果1的个数少于一半
		print("00")
	if(n0<=(L/2) and L/2<=n0+x):
		if(poker[L-1]=='1' or (poker[L-1]=='?' and n1+1 <= (L+1)/2)):
			print("01")
		if(poker[L-1]=='0' or (poker[L-1]=='?' and n0+1 <= L/2)):
			print("10") 
	
	if(n0<=(L-2)/2):
		print("11")
