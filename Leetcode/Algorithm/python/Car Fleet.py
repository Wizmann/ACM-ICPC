class Solution(object):
    def carFleet(self, target, position, speed):
        n = len(position)
        ns = zip(position, speed)
        
        ns.sort(key=lambda (p, s): p, reverse=True)
        
        pre = -1
        ans = 0
        cnt = 0
        for (p, s) in ns:
            t = 1.0 * (target - p) / s
            if t <= pre:
                cnt += 1
            else:
                cnt = 1
                ans += 1
                pre = t

        return ans
