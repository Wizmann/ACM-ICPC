INF = 0xdeadbeef

class Solution(object):
    def summaryRanges(self, nums):
        pre = -INF
        st = -INF
        nums.append(INF)
        res = []
        
        for num in nums:
            if num == pre + 1:
                pre = num
            else:
                if pre != -INF:
                    if pre != st:
                        res.append('%s->%s' % (st, pre))
                    else:
                        res.append(str(st))
                st = num
                pre = num
        return res
