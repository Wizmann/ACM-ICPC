from collections import Counter

class Solution(object):
    def countCharacters(self, words, chars):
        res = 0
        cc = Counter(chars)
        for word in words:
            ww = Counter(word)
            
            for key, value in ww.items():
                if cc.get(key, 0) < value:
                    break
            else:
                res += len(word)
        return res
