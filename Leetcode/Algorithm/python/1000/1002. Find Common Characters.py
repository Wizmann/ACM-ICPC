from collections import Counter

class Solution(object):
    def commonChars(self, A):
        cur = A[0]
        d = Counter(cur)
        
        for word in A:
            for (key, value) in d.items():
                d[key] = min(d[key], word.count(key))
        
        res = ''
        for (key, value) in d.items():
            if value:
                res += key * value
        return list(res)
