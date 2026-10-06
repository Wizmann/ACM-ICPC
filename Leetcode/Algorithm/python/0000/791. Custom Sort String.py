INF = 10 ** 10

class Solution(object):
    def customSortString(self, S, T):
        d = dict(map(lambda (idx, value): (value, idx), enumerate(S)))
        return ''.join(sorted(T, key=lambda c: d.get(c, INF)))
