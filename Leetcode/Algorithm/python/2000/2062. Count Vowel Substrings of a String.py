class Solution(object):
    def countVowelSubstrings(self, word):
        n = len(word)
        cnt = 0
        for i in xrange(n):
            for j in xrange(i, n):
                sub = word[i: j + 1]
                if set(sub) == set('aeiou'):
                    cnt += 1
        return cnt
