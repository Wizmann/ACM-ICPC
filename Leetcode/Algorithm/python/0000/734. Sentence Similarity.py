class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        d = set(map(lambda l: (l[0], l[1]), pairs))
        n, m = len(words1), len(words2)
        
        if n != m:
            return False
        
        for i in xrange(n):
            if words1[i] == words2[i]:
                continue
            p = words1[i], words2[i]
            q = words2[i], words1[i]
            if p not in d and q not in d:
                return False
            
        return True
        
        
