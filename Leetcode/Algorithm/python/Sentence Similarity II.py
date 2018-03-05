class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = [i for i in xrange(n)]
        
    def make_union(self, a, b):
        self.father[self.find_father(a)] = self.find_father(b)
        
    def find_father(self, x):
        if self.father[x] == x:
            return self.father[x]
        self.father[x] = self.find_father(self.father[x])
        return self.father[x]

class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        d = {}
        idx = 0
        ds = DisjointSet(3000)
        for (a, b) in pairs:
            if a not in d:
                d[a] = idx + 1
                idx += 1
            if b not in d:
                d[b] = idx + 1
                idx += 1
            ds.make_union(d[a], d[b])
            
        n = len(words1)
        m = len(words2)
        
        if n != m:
            return False
        
        for i in xrange(n):
            a, b = words1[i], words2[i]
            if a == b:
                continue
            elif (a in d) and (b in d):
                a = ds.find_father(d[a])
                b = ds.find_father(d[b])
                
                if a != b:
                    return False
            else:
                return False
        return True
