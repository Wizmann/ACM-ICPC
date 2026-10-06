from collections import Counter
import string

class Solution(object):
    def checkAlmostEquivalent(self, word1, word2):
        c1 = Counter(word1)
        c2 = Counter(word2)
        
        for c in string.ascii_lowercase:
            diff = abs(c1.get(c, 0) - c2.get(c, 0))
            if diff > 3:
                return False
            
        return True
