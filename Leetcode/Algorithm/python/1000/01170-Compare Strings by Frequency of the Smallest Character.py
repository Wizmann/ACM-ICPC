from collections import Counter

class Solution(object):
    def freq(self, word):
        c = Counter(word)
        return min(c.items())[1]
    
    def numSmallerByFrequency(self, queries, words):
        w = sorted(map(self.freq, words))
        res = []
        print w
        for query in queries:
            c = self.freq(query)
            print c
            l, r = 0, len(w) - 1
            while l <= r:
                m = (l + r) / 2
                if w[m] > c:
                    r = m - 1
                else:
                    l = m + 1
            res.append(len(w) - l)
        return res
