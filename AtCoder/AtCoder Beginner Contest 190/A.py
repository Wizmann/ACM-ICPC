#coding=utf-8

a, b, c = map(int, raw_input().split())

candies = [a, b]
while True:
    if candies[c] <= 0:
        break
    candies[c] -= 1
    c ^= 1

if c == 0:
    print 'Aoki'
else:
    print 'Takahashi'

'''
^^^TEST^^^
2 1 0
-----
Takahashi
$$$TEST$$$

^^^TEST^^^
2 2 0
----
Aoki
$$$TEST$$$

^^^TEST^^^
2 2 1
----
Takahashi
$$$TEST$$$
'''
