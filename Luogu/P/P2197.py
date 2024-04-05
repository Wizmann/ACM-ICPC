T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    if reduce(lambda x, y: x ^ y, ns):
        print 'Yes'
    else:
        print 'No'

'''
^^^TEST^^^
2
2
1 1
2
1 0
---
No
Yes
$$$TEST$$$
'''
