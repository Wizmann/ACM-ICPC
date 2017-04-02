class Solution(object):
    def is_subseq_of(self, a, b):
        i, j = 0, 0
        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                i += 1
                j += 1
            else:
                j += 1
        return i == len(a)
    
    def findLUSlength(self, strs):
        n = len(strs)
        
        strs1 = []
        
        for i in xrange(n):
            flag = True
            for j in xrange(n):
                if i == j:
                    continue
                if self.is_subseq_of(strs[i], strs[j]):
                    flag = False
            if flag:
                strs1.append(strs[i])
                
        strs = strs1
        if not strs:
            return -1
        return max(map(len, strs))
