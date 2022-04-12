ns = raw_input().strip()
u = int(ns, 2)
print '{:04b}'.format(u >> 1)

'''
^^^^TEST^^^
1011
-----
0101
$$$TEST$$$

^^^TEST^^^
1111
-----
0111
$$$TEST$$$
'''
