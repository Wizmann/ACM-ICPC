#python3
raw_input = input
xrange = range


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    if n == 1:
        print(1)
    elif n == 2:
        print(9)
    else:
        print(max(n * n + n * n - 1 + n * n - 2 + n * n - n - 1,
                  n * n - 1 + n * n - 1 - n + n * n - n + n * n - n - 2 + n * n - 2 * n - 1))

'''
^^^^^TEST^^^^^^
5
1
2
3
4
5
------------
1
9
29
56
95
$$$$$$$TEST$$$$$
'''


