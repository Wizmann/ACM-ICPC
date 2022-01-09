class Solution(object):
    def mergeTriplets(self, triplets, target):
        ta, tb, tc = target
        ts = filter(lambda abc: abc[0] <= ta and abc[1] <= tb and abc[2] <= tc, triplets)
        return tuple(target) == reduce(
            lambda (a1, b1, c1), (a2, b2, c2) : (max(a1, a2), max(b1, b2), max(c1, c2)), ts, (0, 0, 0))
