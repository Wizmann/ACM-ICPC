class Solution(object):
    def subStrHash(self, s, power, modulo, k, hashValue):
        char_to_num = lambda c: ord(c) - ord('a') + 1
        res = []
        h = 0
        n = len(s)
        s = s[::-1]
        res = []
        for i in xrange(k):
            h = h * power + char_to_num(s[i])
            h %= modulo
        if h == hashValue:
            res.append(s[:k][::-1])

        for i in xrange(k, n):
            h -= pow(power, k - 1, modulo) * char_to_num(s[i - k]) % modulo
            h = ((h % modulo) % modulo + modulo) % modulo
            h *= power
            h += char_to_num(s[i])
            h %= modulo
            if h == hashValue:
                res.append(s[i - k + 1: i + 1][::-1])
        return res[-1]

'''
^^^^TEST^^^
"aafbx"
31
100
3
32
-------
"fbx"
$$$TEST$$$

^^^^^^TEST^^^^
"leetcode"
7
20
2
0
---------
"ee"
$$$TEST$$$$

^^^^TEST^^^
"fbxzaad"
31
100
3
32
-------
"fbx"
$$$TEST$$$

'''

