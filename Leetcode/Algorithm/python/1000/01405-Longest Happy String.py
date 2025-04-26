# https://leetcode.com/problems/longest-happy-string/
class Solution(object):
    def longestDiverseString(self, a, b, c):
        alpha = [(a, 'a'), (b, 'b'), (c, 'c')]
        res = ''
        while True:
            alpha.sort()
            if alpha[-1][-1] == 0:
                break
            if len(res) < 2 or len(set([alpha[-1][-1], res[-1], res[-2]])) > 1:
                (cnt, c) = alpha.pop()
                if cnt == 0:
                    break
                res += c
                alpha.append((cnt - 1, c))
            else:
                (cnt, c) = alpha.pop(1)
                if cnt == 0:
                    break
                res += c
                alpha.append((cnt - 1, c))
        return res
