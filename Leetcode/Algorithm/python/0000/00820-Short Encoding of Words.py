class Solution(object):
    def minimumLengthEncoding(self, words):
        words = sorted(map(lambda s: s[::-1], words))
        n = len(words)
        
        res = 0
        pre = ''
        for i in xrange(n):
            if words[i].startswith(pre):
                pre = words[i]
            else:
                res += len(pre) + 1
                pre = words[i]
        if pre:
            res += len(pre) + 1
        return res
