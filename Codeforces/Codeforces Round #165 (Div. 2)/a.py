#3045721	 Feb 1, 2013 7:35:51 PM	Wizmann	 A - Fancy Fence	 Python	Accepted	 46 ms	 0 KB
n = int(raw_input())
for i in xrange(n):
    x = int(raw_input())
    print 'YES' if 360 % (180-x) == 0 else 'NO'
