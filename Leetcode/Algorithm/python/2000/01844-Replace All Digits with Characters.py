class Solution(object):
    def replaceDigits(self, s):
        res = []
        for c in s:
            if c.isdigit():
                c = int(c)
                res.append(chr(ord(res[-1]) + c))
            else:
                res.append(c)
        return ''.join(res)

'''
^^^TEST^^^
"a1c1e1"
------
"abcdef"
$$$TEST$$$
'''

'''
^^^TEST^^^
"a1b2c3d4e"
------
"abbdcfdhe"
$$$TEST$$$
'''
