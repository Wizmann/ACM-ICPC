class Solution(object):
    def reformatNumber(self, number):
        nums = str(filter(lambda c: c.isdigit(), number))
        l, r = 0, len(nums)
        res = []
        while r - l > 4:
            res.append(nums[l: l + 3])
            l += 3
        if r - l == 4:
            res.append(nums[l: l + 2])
            res.append(nums[l + 2:])
        else:
            res.append(nums[l:])
        return '-'.join(res)
        
