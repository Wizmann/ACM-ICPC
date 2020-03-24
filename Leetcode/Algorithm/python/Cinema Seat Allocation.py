from collections import defaultdict

class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        d = defaultdict(int)
        for (l, c) in reservedSeats:
            l -= 1
            c -= 1
            d[l] |= (1 << c)
        res = 2 * (n - len(d))
        for num in d.values():
            if not (num & 0b0111111110):
                res += 2
            elif not (num & 0b0111100000) or not (num & 0b0000011110) or not (num & 0b0001111000):
                res += 1
        return res
