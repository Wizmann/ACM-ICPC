class Solution(object):
    def numJewelsInStones(self, J, S):
        J = set(J)
        return sum([1 if s in J else 0 for s in S])
