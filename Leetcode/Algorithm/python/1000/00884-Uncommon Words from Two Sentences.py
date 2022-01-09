from collections import defaultdict

class Solution(object):
    def uncommonFromSentences(self, A, B):
        A = A.split()
        B = B.split()
        da, db = defaultdict(int), defaultdict(int)
        
        for word in A:
            da[word] += 1
        for word in B:
            db[word] += 1
            
        return [word for word in A + B if da[word] + db[word] == 1 and da[word] ^ db[word] == 1]
