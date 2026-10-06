import string
class Solution(object):
    def isAlienSorted(self, words, order):
        d = dict(zip(order, string.lowercase))
        for i, word in enumerate(words):
            words[i] = ''.join(map(lambda c: d[c], word))
        return words == sorted(words)
