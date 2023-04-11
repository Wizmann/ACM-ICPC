class Solution(object):
    def vowelStrings(self, words, left, right):
        cnt = 0
        for i in xrange(left, right + 1):
            if words[i][0] in 'aeiou' and words[i][-1] in 'aeiou':
                cnt += 1
        return cnt
