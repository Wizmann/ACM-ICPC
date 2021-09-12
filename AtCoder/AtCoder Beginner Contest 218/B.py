ns = map(int, raw_input().split())

print ''.join([chr(ord('a') + x - 1) for x in ns])


'''
^^^TEST^^^
2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
-------
bacdefghijklmnopqrstuvwxyz
$$$TEST$$$

^^^TEST^^^
5 11 12 16 25 17 18 1 7 10 4 23 20 3 2 24 26 19 14 9 6 22 8 13 15 21
-------
eklpyqragjdwtcbxzsnifvhmou
$$$TEST$$$
'''

