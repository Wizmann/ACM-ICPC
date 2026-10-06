from collections import Counter

class Solution(object):
    def distinctDifferenceArray(self, nums):
        st1, st2 = set(), Counter(nums)
        res = []
        for i, num in enumerate(nums):
            st1.add(num)
            st2[num] -= 1
            if st2[num] == 0:
                del st2[num]
            res.append(len(st1) - len(st2))
        return res
