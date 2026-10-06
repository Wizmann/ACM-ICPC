MAGIC = 29
MOD = 0xdeadbeef

class Solution(object):
    def palindromePairs(self, words):
        d = dict([(self.get_hash(word), i) for i, word in enumerate(words)])
        res = []
        print d
        
        for i, word in enumerate(words):
            m = len(word)
            h1, h2, u = 0, 0, 1
            
            #print word
            for j in xrange(m + 1):
                #print h1, h2, word[j:], word[:m - j]
                if h1 in d and d[h1] != i and self.is_palindrome(word[j:]):  
                    res.append((i, d[h1]))
                    
                if h2 in d and d[h2] != i and self.is_palindrome(word[:m - j]):
                    res.append((d[h2], i))
                
                if j < m:
                    c1, c2 = word[j], word[m - j - 1]
                    h1 = ((u * (ord(c1) - ord('a') + 1)) + h1) % MOD
                    h2 = (h2 * MAGIC + ord(c2) - ord('a') + 1) % MOD
                    u = (u * MAGIC) % MOD
                    
        return list(set(res))

    def is_palindrome(self, word):
        i, j = 0, len(word) - 1
        while i <= j:
            if word[i] == word[j]:
                i += 1
                j -= 1
            else:
                return False
        return True 
        
    def get_hash(self, word):
        h1 = 0
        for c in word:
            h1 = (h1 * MAGIC + ord(c) - ord('a') + 1) % MOD
        return h1
            
        
