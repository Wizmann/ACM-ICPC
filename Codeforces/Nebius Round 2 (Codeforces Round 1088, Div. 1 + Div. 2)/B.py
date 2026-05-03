import math
MOD = 676767677

T = int(raw_input())

for case_ in xrange(T):
    a, b = map(int, raw_input().split())
    u = abs(a - b)
    
    st = set([1])
    for i in xrange(1, int(math.sqrt(u)) + 1):
        if u % i == 0:
            st.add(i)
            st.add(u / i)
    print len(st)

    res = [1] * a + [-1] * b
    print ' '.join(map(str, res))

'''
^^^^TEST^^^
4
2 0
1 1
6 7
1 3
-----------
2
1 1
1
1 -1
1
-1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1
2
-1 -1 -1 1
$$$$$$TEST$$$$$
'''




