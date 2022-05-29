(a, b, c) = map(int, raw_input().split())


ns = sorted([a, b, c])

print 'Yes' if ns[1] == b else 'No'

'''
^^^^TEST^^^^
5 3 2
-----
Yes
$$$TEST$$$


^^^^TEST^^^^
100 100 100
-----
Yes
$$$TEST$$$

^^^^TEST^^^^
2 5 3
-----
No
$$$TEST$$$
'''
