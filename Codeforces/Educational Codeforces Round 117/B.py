T = int(raw_input())

def solve(n, a, b):
    left = [a]
    right = [b]
    for i in xrange(n, b, -1):
        if i == a:
            continue
        left.append(i)
    for i in xrange(1, a):
        if i == b:
            continue
        right.append(i)
    for i in xrange(a + 1, b):
        if len(left) < n / 2:
            left.append(i)
        elif len(right) < n / 2:
            right.append(i)
    # print left, right
    if len(left) == n / 2 and len(right) == n / 2:
        return left + right
    else:
        return []

for case_ in xrange(T):
    n, a, b = map(int, raw_input().split())
    res = solve(n, a, b)
    if res:
        print ' '.join(map(str, res))
    else:
        print -1

'''
^^^TEST^^^
7
6 2 5
6 1 3
6 4 3
4 2 4
10 5 3
2 1 2
2 2 1
----
4 2 6 5 3 1
-1
6 4 5 1 3 2 
3 2 4 1 
-1
1 2 
2 1 
$$$TEST$$$
'''

