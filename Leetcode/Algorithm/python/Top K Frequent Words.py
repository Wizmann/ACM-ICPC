from collections import defaultdict

class Solution(object):
    def topKFrequent(self, words, k):
        d = defaultdict(int)
        for word in words:
            d[word] += 1
        return map(lambda (x, y): y, sorted(map(lambda (x, y): (-y, x), d.items()))[:k])
