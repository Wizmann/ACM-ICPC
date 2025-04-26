class Solution(object):
    def maxVowels(self, s, k):
        p, q = 0, 0
        cnt = 0
        res = 0
        n = len(s)
        while q < n:
            if s[q] in 'aeiou':
                cnt += 1
            q += 1
            while q - p > k:
                if s[p] in 'aeiou':
                    cnt -= 1
                p += 1
            res = max(res, cnt)
        return res
