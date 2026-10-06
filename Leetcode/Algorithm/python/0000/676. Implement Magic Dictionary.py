from collections import defaultdict

class MagicDictionary(object):

    def __init__(self):
        self.dict = defaultdict(set)
        self.origin = {}
        
    def buildDict(self, dict):
        for i, word in enumerate(dict):
            self.origin[word] = i
            words = self.fuzzy(word)
            for word in words:
                self.dict[word].add(i)
        
    def search(self, word):
        nr = self.origin.get(word, -1)
        words = self.fuzzy(word)
        #print words, self.dict
        for word in words:
            if word in self.dict:
                st = self.dict[word]
                if st - set([nr]):
                    return True
        return False
        
    def fuzzy(self, word):
        res = []
        word = list(word)
        n = len(word)
        for i in xrange(n):
            pattern = word[:]
            pattern[i] = '*'
            res.append(''.join(pattern))
        return res
        


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
