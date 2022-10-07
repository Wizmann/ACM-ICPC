from collections import Counter

class Solution(object):
    def equalFrequency(self, word):
        c = Counter(word)
        cnts = sorted(c.values())
        if len(cnts) == 1:
            return True
        if cnts[0] == 1 and len(set(cnts[1:])) == 1:
            return True
        cnts[-1] -= 1
        if len(set(cnts)) == 1:
            return True
        return False
