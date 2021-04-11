def check(res):
    cnt = 0
    for c in res:
        if c == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            return False
    return True

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    s = map(int, raw_input())

    ones = sum(s)
    zeros = n - ones

    if ones % 2 != 0 or zeros % 2 != 0:
        print 'NO'
        continue

    res1 = ['x' for i in xrange(n)]
    res2 = ['x' for i in xrange(n)]

    c1 = 0
    for i in xrange(n):
        if s[i] == 1:
            c1 += 1
            if c1 <= ones / 2:
                res1[i] = '('
                res2[i] = '('
            else:
                res1[i] = ')'
                res2[i] = ')'

    c2 = 0
    for i in xrange(n):
        if s[i] == 0:
            c2 += 1
            if c2 % 2 == 1:
                res1[i] = '('
                res2[i] = ')'
            else:
                res1[i] = ')'
                res2[i] = '('

    if not check(res1) or not check(res2):
        print 'NO'
    else:
        print 'YES'
        print ''.join(res2)
        print ''.join(res1)


'''
^^^TEST^^^
3
6
101101
10
1001101101
4
1100
----
YES
()()()
((()))
YES
()()((()))
(())()()()
NO
$$$TEST$$$
'''
