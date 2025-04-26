class Solution(object):
    def constructArray(self, n, k):
        prefix = []
        for i in xrange((k + 2) / 2):
            prefix.append(i + 1)
            if i + 1 != k + 1 - i:
                prefix.append(k + 1 - i)
        suffix = range(k + 2, n + 1)
        return prefix + suffix

assert Solution().constructArray(3, 1) == [1, 2, 3]
assert Solution().constructArray(3, 2) == [1, 3, 2]
assert Solution().constructArray(10, 9) == [1, 10, 2, 9, 3, 8, 4, 7, 5, 6]
assert Solution().constructArray(5, 2) == [1, 3, 2, 4, 5]
assert Solution().constructArray(6, 2) == [1, 3, 2, 4, 5, 6]
