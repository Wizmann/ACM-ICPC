#coding=utf-8

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    st = set()
    rem = []

    for num in ns:
        if num in st:
            rem.append(num)
        else:
            st.add(num)
    res = sorted(st) + sorted(rem)
    print ' '.join(map(str, res))

'''
^^^TEST^^^
3
7
4 2 0 1 3 3 7
5
2 2 8 6 9
1
0
-----
0 1 2 3 4 7 3 
2 6 8 9 2 
0 
$$$TEST$$$
'''
