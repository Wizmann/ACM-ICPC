class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        d = {}
        if t == 0:
            return not len(set(nums)) == len(nums)
            
        for i, u in enumerate(nums):
            u /= t
            for bucket in [u - 1, u, u + 1]:
                if bucket not in d:
                    continue
                for j in d[bucket]:
                    if abs(nums[i] - nums[j]) <= t:
                        return True
            
            if u not in d:
                d[u] = set()
            d[u].add(i)
            
            if i >= k:
                v = nums[i - k] / t
                d[v].remove(i - k)
        return False
                
            
