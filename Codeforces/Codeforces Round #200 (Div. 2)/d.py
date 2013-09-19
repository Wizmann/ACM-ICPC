#coding=utf-8
#4504666	 Sep 19, 2013 7:45:39 PM	Wizmann	 D - Alternating Current	 Python 2	Accepted	124 ms	1180 KB

s = raw_input()

stack = []
for ch in s:
    if not stack or stack[-1] != ch:
        stack.append(ch)
    else:
        stack.pop()
        
if not stack:
    print "Yes"
else:
    print "No"
