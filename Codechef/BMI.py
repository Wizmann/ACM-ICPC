T = int(raw_input())

for case_ in xrange(T):
    (m, h) = map(int, raw_input().split())
    bmi = m / h / h

    if bmi <= 18:
        print 1
    elif 19 <= bmi <= 24:
        print 2
    elif 25 <= bmi <= 29:
        print 3
    else:
        print 4

'''
^^^^TEST^^^
3
72 2
80 2
120 2
-----
1
2
4
$$$$TEST$$$$
'''
