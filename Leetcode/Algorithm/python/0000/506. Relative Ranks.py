class Solution(object):
    def findRelativeRanks(self, nums):
        medals = sorted(nums, reverse=True)
        d = {}
        for i, medal in enumerate(medals):
            d[medal] = i + 1
            
        res = []
        for num in nums:
            item = None
            if d[num] == 1:
                item = "Gold Medal"
            elif d[num] == 2:
                item = "Silver Medal"
            elif d[num] == 3:
                item = "Bronze Medal"
            else:
                item = str(d[num])
            res.append(item)
        return res
        
        
