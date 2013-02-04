#3047360	 Feb 1, 2013 7:45:14 PM	Wizmann	 B - Multithreading	 Python	Accepted	 140 ms	 5500 KB
import sys,re,os

n = int(raw_input())
nums = map(int,raw_input().split())[::-1]

idx = 0
pre = n + 1
for num in nums:
    if num < pre:
        idx += 1
        pre = num
    else:
        break
print n-idx

