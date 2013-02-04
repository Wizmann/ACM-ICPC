#3063628	 Feb 2, 2013 4:08:47 PM	Wizmann	 C - Magical Boxes	 Python	Accepted	1109 ms	20800 KB
import sys,re,os

sys.stdin=open('c.txt')

n = int(raw_input())
boxes = []

for i in xrange(n):
    a,b = map(int,raw_input().split())
    boxes.append({'sz': a, 'num': b})

boxes = sorted(boxes, key = lambda x : x['sz'])

sz, num = -1, -1

for i,item in enumerate(boxes):
    if sz == -1:
        sz, num = item['sz'], item['num']
    else:
        for i in xrange(item['sz']-sz):
            num = num / 4 + (1 if num % 4 != 0 else 0)
            if num == 1:
                break
        sz = item['sz']
        num = max(num, item['num'])
        #print num

while num > 4:
    num = num / 4 + (1 if num % 4 != 0 else 0)
    sz += 1
    #print num,sz
print sz + 1


