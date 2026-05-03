from collections import Counter

def solve(n, A, B, k):
    for i in xrange(k, n):
        pre = A[i - k]
        if B[i - k] != -1 and B[i - k] != pre:
            return False
        B[i - k] = pre
        nxt = A[i]
        if B[i] != -1 and B[i] != nxt:
            return False
        B[i] = nxt
    cnt = Counter(B)
    del cnt[-1]
    if max(cnt.values() + [-1]) > 1:
        return False
    return True

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())

    print 'YES' if solve(n, A, B, k) else 'NO'

'''
^^^^^TEST^^^^
4
5 5
1 2 3 4 5
3 1 5 2 4
5 4
4 1 2 5 3
2 -1 -1 -1 -1
6 4
1 2 4 3 5 6
-1 -1 3 -1 -1 -1
6 4
1 2 4 3 5 6
-1 -1 3 3 -1 -1
-----------
YES
NO
YES
NO
$$$$$$TEST$$$$$$

^^^^^TEST^^^^
2
1 1
1
-1
1 1
1
1
-----------
YES
YES
$$$$$$TEST$$$$$$
'''


