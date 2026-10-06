#python3

INF = 10 ** 10
xrange = range

class Solution(object):
    def longestBalanced(self, s):
        ns = [0, 0, 0]
        n = len(s)
        d = [{(0, 0, 0): 0} for i in xrange(8)]
        res = 0
        for i in xrange(1, n + 1):
            x = ord(s[i - 1]) - ord('a')
            ns[x] += 1

            for j in xrange(1, 1 << 3):
                needle = ns[:]
                mini = INF
                for k in xrange(3):
                    if ((1 << k) & j):
                        mini = min(mini, needle[k])
                for k in xrange(3):
                    if ((1 << k) & j):
                        needle[k] -= mini
                needle = tuple(needle)
                if needle in d[j]:
                    res = max(res, i - d[j][needle])
                else:
                    d[j][needle] = i
        return res
