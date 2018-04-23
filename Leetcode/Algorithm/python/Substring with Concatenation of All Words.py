class Solution(object):
    def findSubstring(self, s, words):
        if not words:
            return []
        n = len(s)
        m = len(words[0])
        d = {}
        for word in words:
            d[word] = d.get(word, 0) + 1
        
        res = []
        for i in xrange(m):
            st = {}
            p = i
            for j in xrange(i, n, m):
                cur = s[j: j + m]
                if cur not in d:
                    p = j + m
                    st = {}
                else:
                    #print cur, st.get(cur, 0), d[cur]
                    while st.get(cur, 0) >= d[cur]:
                        pre = s[p: p + m]
                        st[pre] -= 1
                        if st[pre] == 0:
                            del st[pre]
                        p += m
                    
                    st[cur] = st.get(cur, 0) + 1
                #print cur, st, d
                if st == d:
                    res.append(p)
        return res
