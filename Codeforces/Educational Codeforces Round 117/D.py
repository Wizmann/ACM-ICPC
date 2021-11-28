T = int(raw_input())

for case_ in xrange(T):
    a, b, x = map(int, raw_input().split())
    
    while a and b:
        if a < b:
            a, b = b, a
        if a >= x and (a - x) % b == 0:
            print 'YES'
            break
        a = a % b
    else:
        print 'NO'

'''
^^^^TEST^^^
8
6 9 3
15 38 7
18 8 8
30 30 30
40 50 90
24 28 20
365 216 52
537037812705867558 338887693834423551 3199921013340
--------
YES
YES
YES
YES
NO
YES
YES
YES
$$$TEST$$$
'''

 