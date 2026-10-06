class Solution(object):
    def orderlyQueue(self, S, k):
        n = len(S)
        if k == 1:
            mini = S
            for i in xrange(n):
                S = S[1:] + S[0]
                mini = min(mini, S)
            return mini
        else:
            return ''.join(sorted(S))

assert Solution().orderlyQueue('xxqjzq', 2) == "jqqxxz"
assert Solution().orderlyQueue('xmvzi', 2) == "imvxz"
