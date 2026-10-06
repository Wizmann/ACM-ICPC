from typing import List
from collections import Counter

class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        count = Counter(nums)
        distinct_nums = sorted(count)
        max_count = max(count.values())

        ans = []

        for round_idx in range(1, max_count + 1):
            for num in distinct_nums:
                if count[num] >= round_idx:
                    ans.append(num)

        return ans
