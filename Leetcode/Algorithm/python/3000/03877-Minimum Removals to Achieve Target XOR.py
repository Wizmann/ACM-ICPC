class Solution(object):
    def minRemovals(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        INF = 10 ** 9
        memo = {}

        def dfs(i, cur_xor):
            key = (i, cur_xor)
            if key in memo:
                return memo[key]

            if i == n:
                if cur_xor == target:
                    return 0
                return INF

            # Option 1: remove nums[i]
            remove_cost = 1 + dfs(i + 1, cur_xor)
            # Option 2: keep nums[i]
            keep_cost = dfs(i + 1, cur_xor ^ nums[i])

            best = remove_cost if remove_cost < keep_cost else keep_cost
            memo[key] = best
            return best

        ans = dfs(0, 0)
        return -1 if ans >= INF else ans
