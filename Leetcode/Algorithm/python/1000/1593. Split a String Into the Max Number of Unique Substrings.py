INF = 10 ** 10

class Solution(object):
    def maxUniqueSplit(self, s):
        n = len(s)
        res = -INF
        for i in xrange(1 << (n - 1)):
            d = []
            for j in xrange(n - 1):
                if i & (1 << j):
                    d.append(j + 1)
            d.append(n)
            if len(d) <= res:
                continue
            st = set()
            pre = 0
            for deli in d:
                sub = s[pre: deli]
                if sub in st:
                    break
                else:
                    st.add(sub)
                    pre = deli
            else:
                # print d, st
                res = max(res, len(d))
        return res
