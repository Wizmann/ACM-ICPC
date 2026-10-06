from collections import defaultdict, Counter
import string

INF = 10 ** 100

class Solution(object):
    def minimizeStringValue(self, s):
        d = defaultdict(int)
        s = list(s)
        actions = []
        d = Counter(s)
        for i, c in enumerate(s):
            if c == '?':
                minc = ''
                minv = INF
                for nxt in string.ascii_lowercase:
                    if minv > d[nxt] + 1:
                        minv = d[nxt] + 1
                        minc = nxt
                actions.append(minc)
                d[minc] += 1
        actions.sort(reverse=True)
        for i, c in enumerate(s):
            if c == '?':
                s[i] = actions.pop()
        return ''.join(s)
