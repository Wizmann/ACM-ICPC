#coding=utf-8

d = {
    '0': '0',
    '1': '1',
    '6': '9',
    '8': '8',
    '9': '6'
}

s = raw_input()
print ''.join(map(lambda c: d[c], s))[::-1]

'''
^^^TEST^^^
0601889
-----
6881090
$$$TEST$$$
'''
