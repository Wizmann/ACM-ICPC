T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    
    if n >= 2:
        res = [2] * n
    else:
        res = [1] * n

    print ' '.join(map(str, res))

'''
^^^^^TEST^^^^
2
1
1
3
2 1 3
-----------
1
2 2 2
$$$$TEST$$$$$

^^^^^TEST^^^^
1
5
1 2 3 4 5
-----------
2 2 2 2 2
$$$$TEST$$$$$
'''

