class Solution(object):
    def findMinMoves(self, machines):
        if not machines:
            return 0
        n = len(machines)
        if sum(machines) % n != 0:
            return -1
            
        ave = sum(machines) / n
        
        dp0 = [0 for i in xrange(n)]
        dp1 = [0 for i in xrange(n)]
        
        cnt = 0
        for i, num in enumerate(machines[:-1]):
            num += cnt
            cnt = 0
            if num > ave:
                dp1[i] += abs(num - ave)
            else:
                dp0[i] += abs(num - ave)
            cnt = num - ave
        ans = 0
        for i in xrange(n):
            a = 0 if i == 0 else dp0[i - 1]
            b = dp1[i]
            ans = max(ans, a + b)
        return ans
        
S = Solution()

assert(S.findMinMoves([1,0,5]) == 3)
assert(S.findMinMoves([0,3,0]) == 2)
assert(S.findMinMoves([0,2,0]) == -1)
