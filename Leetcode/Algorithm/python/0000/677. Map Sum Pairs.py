class Trie(object):
    def __init__(self):
        self.trie = {}
        self.value = {}
        
    def add(self, word, val):
        if word in self.value:
            delta = val - self.value[word]
        else:
            self.value[word] = val
            delta = val
            
        cur = self.trie
        word += '.'
        for c in word:
            if '~' not in cur:
                cur['~'] = 0
            cur['~'] += delta
            if c not in cur:
                cur[c] = {}
            cur = cur[c]
    def query(self, word):
        cur = self.trie
        for c in word:
            if c in cur:
                cur = cur[c]
            else:
                return 0
        return cur['~']

class MapSum(object):
    def __init__(self):
        self.trie = Trie()

    def insert(self, key, val):
        self.trie.add(key, val)

    def sum(self, prefix):
        return self.trie.query(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
