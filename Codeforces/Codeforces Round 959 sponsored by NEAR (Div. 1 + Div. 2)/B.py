T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    s = map(int, raw_input())
    t = map(int, raw_input())

    if s == t:
        print 'YES'
        continue

    pre = -1
    for i in xrange(n):
        if s[i] == 1:
            pre = i
            break
    if pre == -1:
        print 'NO'
    elif pre == 0:
        print 'YES'
    else:
        if s[:pre] == t[:pre]:
            print 'YES'
        else:
            print 'NO'


'''
^^^^^TEST^^^^
6
1
0
1
7
0110100
0110100
9
100101010
101111110
4
0011
1011
4
0100
0001
8
10110111
01100000
---------------
NO
YES
YES
NO
YES
YES
$$$TEST$$$
'''





