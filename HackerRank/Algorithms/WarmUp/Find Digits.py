# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(raw_input())

for i in xrange(n):
    u = raw_input()
    print len(
        filter(lambda x: x != 0 and int(u) % x == 0, 
               map(int, list(u))
         )
    )
