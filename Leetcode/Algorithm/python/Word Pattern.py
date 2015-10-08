class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strlist = str.split()
        if len(pattern) != len(strlist):
            return False
        
        n = len(pattern)
        d = {}
        rd = {}
        
        for i in xrange(n):
            a = pattern[i]
            b = strlist[i]
            
            if a in d:
                if d[a] != b:
                    return False
            if b in rd:
                if rd[b] != a:
                    return False
            
            d[a] = b
            rd[b] = a
            
        return True
        
