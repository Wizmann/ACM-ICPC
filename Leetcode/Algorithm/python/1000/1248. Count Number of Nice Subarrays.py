class Solution(object):
    def numberOfSubarrays(self, nums, k):
        st = [-1]
        ans = 0
        for i, num in enumerate(nums + [1]):
            if num % 2 == 1:
                st.append(i)
            #print i, num, st
            if len(st) == k + 2:
                l = st[1] - st[0]
                r = st[-1] - st[-2]
                ans += l * r
                st.pop(0)
        return ans
