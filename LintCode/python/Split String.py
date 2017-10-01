class Solution:
    """
    @param: : a string to be split
    @return: all possible split string array
    """

    def splitString(self, s):
        if not s:
            return [[]]
            
        a, b = [ [] ], [ [s[0]] ]
        n = len(s)
        
        for i in xrange(1, n):
            l1 = map(lambda x : x + [s[i - 1] + s[i]], a)
            l2 = map(lambda x: x + [s[i]], b)
            
            a, b = b, l1 + l2
        return b
