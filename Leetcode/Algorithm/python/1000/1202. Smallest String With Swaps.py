from collections import defaultdict

class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        n = len(s)
        visited = [False for i in xrange(n)]
        s = list(s)
        g = defaultdict(list)
        
        for (a, b) in pairs:
            g[a].append(b)
            g[b].append(a)
            
        for i in xrange(n):
            if visited[i]:
                continue
            st = set()
            inq = set([i])
            q = [i]
            while q:
                cur = q.pop()
                inq.remove(cur)
                if cur in st:
                    continue
                st.add(cur)
                for nxt in g[cur]:
                    if nxt not in st and nxt not in inq:
                        q.append(nxt)
                        inq.add(nxt)
            sub = []
            for pos in st:
                visited[pos] = True
                sub.append(s[pos])
            sub.sort()
            st = sorted(st)
            m = len(st)
            for i in xrange(m):
                s[st[i]] = sub[i]
        return ''.join(s)
                
                
