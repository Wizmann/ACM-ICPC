from collections import defaultdict

class Solution(object):
    def minReorder(self, n, connections):
        g = defaultdict(list)
        st = set()
        for (a, b) in connections:
            g[a].append(b)
            g[b].append(a)
            st.add((a, b))
            
        q = [0]
        pre = { 0: -1 }
        res = 0
        while q:
            cur = q.pop(0)
            for nxt in g[cur]:
                if nxt == pre[cur]:
                    continue
                pre[nxt] = cur
                if (nxt, cur) not in st:
                    res += 1
                q.append(nxt)
        return res
                
