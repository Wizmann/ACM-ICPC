from collections import Counter

class Solution(object):
    def makeEqual(self, words):
        c = Counter(''.join(words))
        for (k, v) in c.items():
            if v % len(words) != 0:
                return False
        return True
        
