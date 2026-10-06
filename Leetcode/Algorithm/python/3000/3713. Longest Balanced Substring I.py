class Solution(object):
    def longestBalanced(self, s):
        n = len(s)
        g = [[0] * 26]
        res = 0
        for i in xrange(1, n + 1):
            c = ord(s[i - 1]) - ord('a')
            g.append(g[i - 1][:])
            g[i][c] += 1
            # print(i, g[i])
            for j in xrange(0, i):
                st = set()
                for k in xrange(26):
                    rem = g[i][k] - g[j][k]
                    if rem == 0:
                        continue
                    st.add(rem)
                    if len(st) > 1:
                        break
                if len(st) == 1:
                    res = max(res, i - j)
                    break
        return res

