class Solution(object):
    def divideString(self, s, k, fill):
        rem = (k - len(s) % k) % k
        s += fill * rem

        n = len(s)
        res = []
        for i in xrange(0, n, k):
            res.append(s[i: i + k])
        return res
'''
^^^^TEST^^^
"abcdefghi"
3
"x"
--------------
["abc","def","ghi"]
$$$TEST$$$


^^^^TEST^^^
"abcdefghij"
3
"x"
--------------
["abc","def","ghi","jxx"]
$$$TEST$$$

'''
