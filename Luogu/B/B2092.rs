#python3

xrange = range

n = int(input())
ns = [1] * (n + 1)

for i in xrange(1, n + 1):
    for j in xrange(0, n + 1, i):
        ns[j] ^= 1

for i in xrange(1, n + 1):
    if ns[i] == 0:
        print(i, end=' ')

'''
^^^^TEST^^^^
10
------
1 4 9
$$$$TEST$$$$

^^^^TEST^^^^
5
------
1 4
$$$$TEST$$$$
'''
