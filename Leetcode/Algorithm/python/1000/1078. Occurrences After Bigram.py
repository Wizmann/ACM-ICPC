class Solution(object):
    def findOcurrences(self, text, first, second):
        text = text.split()
        n = len(text)
        assert (n >= 3)
            
        res = []
        a, b = text[0], text[1]
        for i in xrange(2, n):
            c = text[i]
            print a, b, c
            if a == first and second == b:
                res.append(c)
            a, b = b, c
        return res
