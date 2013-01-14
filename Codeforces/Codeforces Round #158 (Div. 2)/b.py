#coding=utf-8
import sys,re,os,math,json
import datetime

if(__name__=='__main__'):
	istr=raw_input()
	res={}
	mini,maxi=datetime.datetime(2013,1,1),datetime.datetime(2015,12,31)
	for i,ch in enumerate(istr):
		t=istr[i:i+10]
		if re.match(r"(?P<dd>\d{2})-(?P<mm>\d{2})-(?P<yy>\d{4})",t):
			try:
				now=datetime.datetime.strptime(t,"%d-%m-%Y")
				if now>=mini and now<=maxi:
					res[now]=res.get(now,0)+1
					#print t,now.strftime("%d-%m-%Y")
			except Exception,e:
				pass
	print max(res.items(),key=lambda x:x[1])[0].strftime("%d-%m-%Y")

