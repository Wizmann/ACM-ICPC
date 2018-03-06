from collections import Counter

class ValidWordAbbr(object):
    def __init__(self, dictionary):
        self.d = set(dictionary)
        self.c = Counter([self.toAbbr(word) for word in self.d])
        
    def toAbbr(self, s):
        n = len(s)
        if n <= 2:
            return s
        else:
            return s[0] + str(n - 2) + s[-1]
        

    def isUnique(self, word):
        abbr = self.toAbbr(word)
        if word in self.d:
            return self.c[abbr] <= 1
        else:
            return self.c[abbr] == 0
        
        


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
