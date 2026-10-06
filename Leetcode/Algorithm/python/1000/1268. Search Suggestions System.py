import string

class Trie(object):
    def __init__(self):
        self.d = {}
        
    def add(self, word):
        cur = self.d
        for c in word:
            if c not in cur:
                cur[c] = {}
            cur = cur[c]
        cur['$'] = 1
        
    def recommand(self, prefix):
        self.res = []
        self.dfs(prefix, self.d, '')
        return self.res
    
    def dfs(self, prefix, cur, word):
        if len(self.res) >= 3:
            return

        if prefix:
            nxt = prefix[0]
            if nxt in cur:
                self.dfs(prefix[1:], cur[nxt], word + prefix[0])
            return
        
        if '$' in cur:
            self.res.append(word)
        for c in string.ascii_lowercase:
            if c in cur:
                self.dfs('', cur[c], word + c)
        
        
class Solution(object):
    def suggestedProducts(self, products, searchWord):
        t = Trie()
        for p in products:
            t.add(p)
        res = []
        word = ''
        for s in searchWord:
            word += s
            r = t.recommand(word)
            res.append(r)
        return res
