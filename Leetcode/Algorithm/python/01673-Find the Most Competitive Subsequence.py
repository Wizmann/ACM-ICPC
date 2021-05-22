from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def mostCompetitive(self, nums, k):
        st = []
        n = len(nums)
        for i, num in enumerate(nums):
            rem = n - i - 1
            while st and num < st[-1]:
                st.pop()
                if len(st) + 1 + rem == k:
                    break
            st.append(num)
            if len(st) + rem == k:
                st = st + nums[i + 1:]
                break
        return st[:k]
                
