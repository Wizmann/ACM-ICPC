#python3
import math
INF = 10 ** 100

T = int(input())
PI = math.pi

for case_ in range(T):
    r, a, b = map(int, input().split())

    tot = 0
    while r:
        tot += PI * r * r
        r *= a
        tot += PI * r * r
        r = r // b

    print('Case #%d: %.10f' % (case_ + 1, tot))



'''
^^^^^TEST^^^
2
1 3 6
5 2 5
----------------
Case #1: 31.415927
Case #2: 455.530935
$$$$TEST$$$

'''


