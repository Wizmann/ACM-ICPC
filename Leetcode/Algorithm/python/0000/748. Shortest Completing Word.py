from collections import Counter

class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        lp = Counter(filter(lambda c: c.isalpha(), licensePlate.lower()))
        res = 'a' * 10000
        for word in words:
            c = Counter(word)
            for (k, v) in lp.items():
                if c.get(k, 0) < v:
                    break
            else:
                if len(word) < len(res):
                    res = word
        return res
