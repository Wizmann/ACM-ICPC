class Solution(object):
    def decodeCiphertext(self, encodedText, rows):
        tot = len(encodedText)
        m = tot / rows
        
        res = []
        for i in xrange(m):
            for j in xrange(rows):
                idx = j * m + i + j
                if idx < tot:
                    res.append(encodedText[idx])
        return ''.join(res).rstrip()
