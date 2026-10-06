from collections import Counter

class Solution(object):
    def findSmallestInteger(self, nums, value):
        nums = map(lambda x: x % value, nums)
        c = Counter(nums)

        mex = 0
        while True:
            x = mex % value
            if c[x]:
                c[x] -= 1
                mex += 1
            else:
                break
        return mex
