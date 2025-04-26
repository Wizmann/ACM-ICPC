class Solution(object):
    def distinctAverages(self, nums):
        nums.sort()
        st = set()
        n = len(nums)
        p, q = 0, n - 1
        while p < q:
            u = nums[p] + nums[q]
            st.add(u)
            p += 1
            q -= 1
        return len(st)
