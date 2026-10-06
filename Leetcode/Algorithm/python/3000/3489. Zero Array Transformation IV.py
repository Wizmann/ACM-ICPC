INF = 10 ** 10

class Solution(object):
    def minZeroArray(self, nums, queries):
        maxi = 0
        for i, num in enumerate(nums):
            maxi = max(maxi, self.solve(i, num, queries))
        if maxi >= INF:
            return -1
        return maxi

    def solve(self, p, num, queries):
        st = set([num])
        step = 0
        for (a, b, c) in queries:
            if 0 in st:
                break
            step += 1
            if a <= p <= b:
                st2 = set()
                for item in st:
                    if item - c >= 0:
                        st2.add(item - c)
                st |= st2
        # print p, num, step, st
        if 0 in st:
            return step
        return INF
            
