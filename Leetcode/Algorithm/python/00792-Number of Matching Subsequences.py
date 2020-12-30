from collections import defaultdict

class Solution(object):
    def numMatchingSubseq(self, S, words):
        d = defaultdict(list)
        
        for word in words:
            d[word[0]].append(word)
            
        n = len(S)
        m = len(words)
        for i in xrange(n):
            if m == 0:
                break
            
            c = S[i]
            u = d[c][:]
            d[c] = []
            
            for word in u:
                word = word[1:]
                if not word:
                    m -= 1
                    continue
                d[word[0]].append(word)
            
        return len(words) - m
