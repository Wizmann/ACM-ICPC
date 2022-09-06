#python3
def median(ns):
    n = len(ns)
    if n % 2 == 0:
        return 0.5 * (ns[n // 2 - 1] + ns[n // 2])
    else:
        return ns[n // 2]

T = int(input())

for case_ in range(T):
    n, m = map(int, input().split())
    ns = sorted(map(int, input().split()), reverse=True)

    tot = sum(ns[:m - 1])
    tot += median(ns[m - 1:])

    print('Case #%d: %.10f\n' % (case_ + 1, tot))


'''
^^^^^TEST^^^^
1
3 2
11 24 10
---------
Case #1: 34.5
$$$TEST$$$$


^^^^TEST^^^^
1
5 1
6 2 5 1 9
------------
Case #1: 5.0
$$$$TEST$$$$

'''


