from collections import Counter

def solve(n, k, A, B):
    free = [-1 for i in xrange(k)]
    for i in xrange(k):
        cur = i
        chain_a = []
        chain_b = []
        while cur < n:
            chain_a.append(A[cur])
            chain_b.append(B[cur])
            cur += k

        st_a = set(chain_a)
        st_b = set(chain_b)
        if len(st_a) == 1:
            if len(st_b) == 1 and (-1 in st_b):
                pass
            elif len(st_b) == 2 and (-1 in st_b):
                free[i] = max(st_b)
            elif len(st_a) == 1 and len(st_b) == 1:
                free[i] = max(st_b)
            else:
                return False
        else:
            m = len(chain_a)
            assert len(chain_b) == m
            delta = set()
            for j in xrange(m):
                if chain_b[j] != -1:
                    if chain_a[j] != chain_b[j]:
                        return False
            free[i] = A[i]

    c = Counter(free)
    for i in xrange(k):
        c[A[i]] -= 1
    x = c[-1]
    del c[-1]
    if max(c.values()) > 0:
        return False
    return sum(c.values()) + x == 0

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())

    if solve(n, k, A, B):
        print 'YES'
    else:
        print 'NO'

'''
^^^^TEST^^^^
5
5 5
1 2 3 4 5
3 1 5 2 4
5 2
1 2 1 2 1
2 -1 -1 -1 -1
6 1
5 6 2 2 4 3
5 -1 -1 2 -1 3
2 1
1 2
2 -1
6 4
1 2 3 4 1 2
2 -1 3 -1 4 -1
-------------
YES
YES
YES
NO
NO
$$$$$$TEST$$$$
'''


