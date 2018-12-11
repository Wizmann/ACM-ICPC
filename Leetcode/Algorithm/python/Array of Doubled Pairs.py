from collections import Counter

class Solution(object):
    def canReorderDoubled(self, A):
        return self.solve(filter(lambda x: x >= 0, A)) \
               and \
               self.solve(filter(lambda x: x < 0, A))
    def solve(self, A):
        A = map(abs, A)
        d = Counter(A)
        A.sort()
        for num in A:
            if d[num] == 0:
                continue
            d[num] -= 1
            if d.get(num * 2, 0):
                d[num * 2] -= 1
            else:
                return False
        return True
