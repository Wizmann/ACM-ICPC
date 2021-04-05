from collections import Counter

class Solution(object):
    def closeStrings(self, word1, word2):
        c1 = Counter(word1)
        c2 = Counter(word2)
        return sorted(c1.keys()) == sorted(c2.keys()) and sorted(c1.values()) == sorted(c2.values())
