#python3

'''LONG LIVE PYTHON2'''
raw_input = input
xrange = range
__map = map
map = lambda func, ns: list(__map(func, ns))
'''LONG LIVE PYTHON2'''

n = int(input())
ns = map(int, input().split())

ave = sum(ns) // n

cost = 0
for i in xrange(n - 1):
    cost += 1 if abs(ns[i] - ave) else 0
    if ns[i] > ave:
        ns[i + 1] += ns[i] - ave
    else:
        ns[i + 1] -= ave - ns[i]
    ns[i] = ave
    # print(ns)
print(cost)


'''
^^^^^TEST^^^^^
4
9 8 17 6
--------
3
$$$TEST$$$$$
'''

