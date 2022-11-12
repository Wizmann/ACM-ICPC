#python3

import sys

INF = 10 ** 10

def bitcount(x):
    res = 0
    while x:
        res += 1
        x //= 2
    return res

for line in sys.stdin:
    n = int(line)
    print(bitcount(n))


'''

^^^^^TEST^^^^
1
2
3
89
90
99
9
----------
1
2
2
7
7
7
4
$$$TEST$$$
'''
