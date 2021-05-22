#coding=utf-8

a, b, c = map(int, raw_input().split())

print sum(map(lambda x: 7 - x, [a, b, c]))

'''
^^^TEST^^^
5 6 4
-----
6
$$$TEST$$$
'''
