n = int(raw_input())
ns = map(int, raw_input().split())

num_p = len(filter(lambda x : x > 0, ns))
num_n = len(filter(lambda x : x < 0, ns))

target = (n + 1) / 2

if num_p >= target:
    print 1
elif num_n >= target:
    print -1
else:
    print 0

'''
^^^^TEST^^^
5
10 0 -7 2 6
-------
1
$$$TEST$$$

^^^^TEST^^^^
7
0 0 1 -1 0 0 2
----
0
$$$TEST$$$$
'''

