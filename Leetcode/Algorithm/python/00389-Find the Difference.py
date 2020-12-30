from collections import Counter

class Solution(object):
    def findTheDifference(self, s, t):
        d = Counter(t)
        for item in s:
            d[item] -= 1
        return ''.join(map(lambda (k, v): k * v if v else '', d.items()))
