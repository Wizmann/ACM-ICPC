n = int(raw_input())
ns = map(int, raw_input().split())

ns1 = filter(lambda x : x % 2 == 1, ns)
ns2 = filter(lambda x : x % 2 == 0, ns)

ns1.sort(reverse=True)
if len(ns1) % 2 == 1:
    ns1.pop()

print sum(ns1) + sum(ns2)


'''
^^^^TEST^^^
3
1 2 3
-------
6
$$$TEST$$$

^^^^TEST^^^^
5
999999999 999999999 999999999 999999999 999999999
----
3999999996
$$$TEST$$$$
'''

