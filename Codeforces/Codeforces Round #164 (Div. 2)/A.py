#3084200	 Feb 8, 2013 7:49:58 PM	Wizmann	 A - Games	 Python	Accepted	46 ms	4 KB
a = [ raw_input().split() for i in xrange(int(raw_input())) ]
print sum( i[0]==j[1] for i in a \
                      for j in a )
