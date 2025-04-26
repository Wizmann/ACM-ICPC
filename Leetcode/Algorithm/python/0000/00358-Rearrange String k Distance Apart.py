from collections import Counter

class Solution(object):
    def rearrangeString(self, s, k):
        if not s:
            return ""
        c = sorted(Counter(s).items(), key=lambda (k, v): v, reverse=True)
        n = len(s)
        maxi = c[0][1]
        mat = [[] for i in xrange(maxi - 1)]
        
        y = 0
        
        for (key, value) in c:
            if value == maxi:
                value -= 1
            for i in xrange(value):
                mat[y].append(key)
                y += 1
                if y >= maxi - 1:
                    y = 0
        res = []
        for i, line in enumerate(mat):
            if len(line) < k:
                return ""
            res += line
        for (key, value) in c:
            if value == maxi:
                res += [key]
        return ''.join(res)
