from collections import Counter

class Solution(object):
    def checkInclusion(self, s1, s2):
        c1 = Counter(s1)
        n = len(s1)
        m = len(s2)
        
        if n > m:
            return False
        
        d = {}
        for i in xrange(n - 1):
            d[s2[i]] = d.get(s2[i], 0) + 1
        #print d
        for i in xrange(n - 1, m):
            d[s2[i]] = d.get(s2[i], 0) + 1
            if self.dict_eq(c1, d):
                return True
            #print d
            d[s2[i - n + 1]] -= 1
        return False
    
    def dict_eq(self, d1, d2):
        for key, value in d1.items():
            if d2.get(key, 0) != value:
                return False
        return True
       
print Solution().checkInclusion("fuck", "youfcukindidit");
print Solution().checkInclusion("fuck", "youfxukindidit");
print Solution().checkInclusion("ab", "eidboaoo");
print Solution().checkInclusion("a", "eidboaoo");
