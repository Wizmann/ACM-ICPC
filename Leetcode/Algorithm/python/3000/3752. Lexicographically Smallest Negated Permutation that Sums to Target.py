class Solution(object):
    def lexSmallestNegatedPerm(self, n, target):
        """
        :type n: int
        :type target: int
        :rtype: List[int]
        """

        pos = []
        neg = []
        tot = (1 + n) * n / 2
        for i in xrange(n, 0, -1):
            tot -= i
            if target <= -i + tot:
                neg.append(-i)
                target -= -i
            else:
                pos.append(i)
                target -= i

        if target != 0:
            return []

        return neg + pos[::-1]

