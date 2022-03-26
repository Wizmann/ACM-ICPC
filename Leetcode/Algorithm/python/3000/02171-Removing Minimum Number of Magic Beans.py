INF = 10 ** 10

class Solution(object):
    def minimumRemoval(self, beans):
        beans.sort()
        
        right = sum(beans)
        left = 0
        ans = INF
        n = len(beans)
        
        for i, num in enumerate(beans):
            ans = min(ans, right - (n - i) * num + left)
            right -= num
            left += num
        return ans
