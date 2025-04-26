class Solution(object):
    def numSplits(self, s):
        l, r = [], []
        
        st = set()
        for c in s:
            st.add(c)
            l.append(len(st))
            
        st = set()
        for c in s[::-1]:
            st.add(c)
            r.append(len(st))
        r = r[::-1]
        
        n = len(s)
        ans = 0
        for i in xrange(n - 1):
            if l[i] == r[i + 1]:
                ans += 1
        return ans
