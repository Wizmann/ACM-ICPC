from collections import Counter

class Solution(object):
    def isPossible(self, nums):
        (a, b, c) = (0, 0, 0)
        counter = sorted(Counter(nums).items(), key=lambda x: x[0])
        pre = min(nums) - 1
        
        for (k, v) in counter:
            if k != pre + 1:
                if a + b != 0:
                    return False
                a, b, c = 0, 0, 0
        
            if v < a:
                return False

            b1 = a
            v -= a

            if v < b:
                return False

            c1 = b
            v -= b

            c1 += min(c, v)
            v -= min(c, v)

            a, b, c = v, b1, c1
            pre = k
        return a + b == 0
            
        
        
