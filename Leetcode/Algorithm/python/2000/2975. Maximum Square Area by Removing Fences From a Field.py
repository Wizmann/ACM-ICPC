import itertools

class Solution(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        s1 = self.enumerate(hFences, m)
        s2 = self.enumerate(vFences, n)
        # print s1, s2
        maxi = max(list(s1 & s2) + [-1])
        if maxi <= 0:
            return -1
        return maxi * maxi % (10 ** 9 + 7)

    def enumerate(self, fs, n):
        s = set()
        fs = fs + [1, n]
        for num1, num2 in itertools.combinations(fs, 2):
            s.add(abs(num1 - num2))
        return s
