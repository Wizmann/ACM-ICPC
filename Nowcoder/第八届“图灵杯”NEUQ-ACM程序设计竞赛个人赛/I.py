import sys
T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    flag = False
    for i in xrange(2, 15 + 1):
        u = (1 << i) - 1
        if n % u == 0:
            flag = True
            break
    if flag:
        sys.stdout.write('YE5')
    else:
        sys.stdout.write('N0')
    if case_ != T - 1:
        print ''

'''
^^^TEST^^^
2
21
20
-----
YE5
N0
$$$TEST$$$
'''
