from collections import defaultdict, Counter

class Solution(object):
    def wordSubsets(self, A, B):
        d = defaultdict(int)
        for needle in B:
            c = Counter(needle)
            for key, value in c.items():
                d[key] = max(d[key], value)
        
        res = []

        for word in A:
            c = Counter(word)
            for key, value in d.items():
                if c.get(key, 0) < value:
                    break
            else:
                res.append(word)
        return res
                
