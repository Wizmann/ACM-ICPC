class Solution(object):
    def countVowels(self, word):
        n = len(word)
        res = 0
        for i, c in enumerate(word):
            if c in 'aeiou':
                l = i + 1
                r = n - i
                res += l * r
        return res
