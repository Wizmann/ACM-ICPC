INF = 10 ** 10
class Solution(object):
    def shortestBeautifulSubstring(self, s, k):
        res = [INF]
        s = [0] + map(int, s)
        n = len(s)

        for i in xrange(1, n):
            if res[0] != INF:
                break
            for j in xrange(1, n):
                if i + j > n:
                    break
                sub = s[j: i + j]
                if sum(sub) == k and sub < res:
                    res = sub[:]
        if res[0] == INF:
            return ''
        return ''.join(map(str, res))
