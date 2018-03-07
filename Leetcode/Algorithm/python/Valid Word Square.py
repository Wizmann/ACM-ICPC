class Solution(object):
    def validWordSquare(self, words):
        n = len(words)
        if n == 0:
            return True
        m = len(words[0])

        if m == 0:
            return False
        if n != m:
            return False

        for i in xrange(m):
            s = ''
            for j in xrange(n):
                if i < len(words[j]):
                    s += words[j][i]
                else:
                    break

            if s != words[i]:
                return False
        return True
