from collections import defaultdict

class Solution(object):
    def findJudge(self, N, trust):
        d = defaultdict(int)
        st = set(range(1, N + 1))
        for (a, b) in trust:
            d[b] += 1
            if a in st:
                st.remove(a)
        if len(st) != 1:
            return -1
        j = list(st)[0]
        if d[j] != N - 1:
            return -1
        return j
