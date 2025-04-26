class Solution(object):
    def maximumNumberOfStringPairs(self, words):
        n = len(words)
        cnt = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if words[i] == words[j][::-1]:
                    cnt += 1
        return cnt