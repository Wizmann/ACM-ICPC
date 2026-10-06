class Solution(object):
    def earliestSecondToMarkIndices(self, nums, indices):
        l, r = 1, len(indices)
        while l <= r:
            m = (l + r) / 2
            if self.check(nums, indices, m):
                r = m - 1
            else:
                l = m + 1
        res = l
        if res > len(indices):
            return -1
        return res

    def check(self, nums, indices, pos):
        st = set()
        rem = 0
        while pos > 0:
            cur = indices[pos - 1]
            val = nums[cur - 1] if cur not in st else 0
            if val == 0 and cur in st:
                rem = max(0, rem - 1)
            st.add(cur)
            rem += val
            pos -= 1
        return len(st) == len(nums) and rem <= 0
