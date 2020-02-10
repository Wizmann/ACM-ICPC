# https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        tot = sum(arr[:k - 1])
        n = len(arr)
        l, r = 0, k - 1
        ans = 0
        while r < n:
            tot += arr[r]
            if r - l + 1 > k:
                tot -= arr[l]
                l += 1
            if tot >= threshold * k:
                ans += 1
            r += 1
        return ans
