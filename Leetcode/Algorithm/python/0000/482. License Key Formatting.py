class Solution(object):
    def licenseKeyFormatting(self, S, K):
        n = len(S)
        S = S[::-1].replace('-', '')
        res = []
        
        for i in xrange(0, n, K):
            res.append(S[i: i + K].upper())
        return '-'.join(filter(lambda x: x.strip(), res))[::-1]

assert Solution().licenseKeyFormatting("2-4A0r7-4k", 4) == "24A0-R74K"
assert Solution().licenseKeyFormatting("2-4A0r7-4k", 3) == "24-A0R-74K"
