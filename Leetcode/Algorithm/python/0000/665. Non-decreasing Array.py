INF = 10 ** 10

class Solution(object):
    def checkPossibility(self, nums):
        n = len(nums)
        pre = -INF
        pivot = -1
        for i, num in enumerate(nums):
            if num < pre:
                if pivot == -1:
                    pivot = i
                else:
                    return False
            pre = num
            
        if pivot == -1:
            return True
            
        
        
        l1 = -INF if pivot - 1 < 0 else nums[pivot - 1]
        r1 = INF if pivot + 1 >= n else nums[pivot + 1]
        
        l2 = -INF if pivot - 2 < 0 else nums[pivot - 2]
        r2 = nums[pivot]

        return l1 <= r1 or l2 <= r2
    
S = Solution()

assert S.checkPossibility([4, 2, 3]) == True

assert S.checkPossibility([1]) == True
assert S.checkPossibility([]) == True
assert S.checkPossibility([1, 2]) == True
assert S.checkPossibility([2, 2]) == True
assert S.checkPossibility([2, 1]) == True

assert S.checkPossibility([4, 2, 1]) == False
assert S.checkPossibility([2, 2, 1, 2, 2]) == True
assert S.checkPossibility([2, 2, 10, 2, 2]) == True
assert S.checkPossibility([2, 2, 1, 2, 1]) == False
assert S.checkPossibility([2, 2, 2, 2, 1]) == True
