class Solution(object):
    def findScore(self, nums):
        n = len(nums)
        pp = sorted(zip(nums, range(n)))
        marked = set()

        score = 0
        for num, idx in pp:
            if idx in marked:
                continue
            score += num
            marked.update([idx - 1, idx, idx + 1])
        return score
