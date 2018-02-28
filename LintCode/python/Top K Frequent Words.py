from collections import Counter

class Solution:
    """
    @param: words: an array of string
    @param: k: An integer
    @return: an array of string
    """
    def topKFrequentWords(self, words, k):
        c = map(lambda (w, c): w, sorted(Counter(words).items(), key=lambda (w, c): (-c, w)))
        return c[:k]
