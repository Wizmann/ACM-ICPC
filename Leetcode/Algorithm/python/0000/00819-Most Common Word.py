from collections import Counter
import re

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        c = Counter(re.sub("[\!\?\'\,\;\.]", " ", paragraph.lower()).split())
        for word in banned:
            del c[word]
        return max(c.items(), key=lambda (word, count): count)[0]
        
