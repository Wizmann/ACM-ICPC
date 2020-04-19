INF = 10 ** 10

class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        mini = INF
        pre = 0
        for num in nums:
            pre += num
            mini = min(mini, pre)
        return max(1, 1 - mini)
