from collections import defaultdict, Counter

INF = 10 ** 10

class Solution(object):
    def rearrangeCharacters(self, s, target):
        mini = INF
        c1 = Counter(s)
        c2 = Counter(target)
        
        for key, value in c2.items():
            u = c1.get(key, 0)
            mini = min(mini, u / value)
        return mini
