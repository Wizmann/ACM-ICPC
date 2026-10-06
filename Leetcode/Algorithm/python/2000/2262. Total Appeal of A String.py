from collections import defaultdict

class Solution(object):
    def appealSum(self, s):
        n = len(s)
        d = defaultdict(list)
        for i, c in enumerate(s):
            d[c].append(i)
            
        res = 0
        for key, vlist in d.items():
            pre = -1
            u = 0
            for p in vlist:
                left = p - pre
                right = n - p
                u += left * right
                # print key, left, right
                pre = p
            # print(u)
            res +=u 
        return res

'''
^^^^TEST^^^^
"abbca"
-------
28
$$$TEST$$$

^^^^TEST^^^^
"code"
-------
20
$$$TEST$$$

'''
