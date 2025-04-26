from collections import Counter

class Solution(object):
    def minDeletions(self, s):
        n = len(s)
        c = Counter(Counter(s).values())
        
        res = 0
        st = []
        for i in xrange(1, max(c.keys()) + 1):
            count = c.get(i, 0)
            if count == 0:
                st.append(i)
            elif count > 1:
                for j in xrange(1, count):
                    if st:
                        pre = st.pop()
                        res += i - pre
                    else:
                        res += i * (count - j)
                        break
        return res
