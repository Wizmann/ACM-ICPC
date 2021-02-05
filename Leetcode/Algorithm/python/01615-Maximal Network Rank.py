from collections import defaultdict

class Solution(object):
    def maximalNetworkRank(self, n, roads):
        g = defaultdict(list)
        st = set()        
        for (a, b) in roads:
            g[a].append(b)
            g[b].append(a)
            st.add((a, b))
            st.add((b, a))
        
        res = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                cur = len(g[i]) + len(g[j])
                if (i, j) in st:
                    cur -= 1
                res = max(res, cur)
        return res
            
