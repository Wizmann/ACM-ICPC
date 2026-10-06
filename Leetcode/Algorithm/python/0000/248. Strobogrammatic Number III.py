class Solution(object):
    def __init__(self):
        self.dp = [0 for i in xrange(100)]
        for i in xrange(1, 100):
            res = 1
            l, r = 0, i - 1
            while l <= r:
                if l == r:
                    res *= 3
                else:
                    if l == 0:
                        res *= 4
                    else:
                        res *= 5
                l += 1
                r -= 1
            self.dp[i] = res + self.dp[i - 1]
            
        self.d = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }
            
    def strobogrammaticInRange(self, low, high):
        if int(low) > int(high):
            return 0
        return self.solve(high) - self.solve(low) + self.solve_one(low)
    
    def solve(self, num):
        l = len(num)
        res = self.dp[l - 1]
        print res+ self.dfs(list(num), 0, l - 1, ['' for i in xrange(l)])
        return res + self.dfs(list(num), 0, l - 1, ['' for i in xrange(l)])
    
    def solve_one(self, num):
        return map(lambda c: self.d.get(c, 'x'), str(num))[::-1] == list(str(num))
    
    def dfs(self, num, l, r, buf):
        res = 0
        if l > r:
            return 1
        elif l == r:
            for c in "018":
                buf[l] = c
                if buf <= num:
                    res += self.dfs(num, l + 1, r - 1, buf)
                buf[l] = ''
        else:
            for (key, value) in self.d.items():
                if key == '0' and l == 0:
                    continue
                buf[l], buf[r] = key, value
                if buf[l] < num[l]:
                    res += (5 ** ((r - l - 1) / 2)) * (3 ** ((r - l - 1) & 1))
                elif buf[l] == num[l] and buf <= num:
                    res += self.dfs(num, l + 1, r - 1, buf)
                buf[l], buf[r] = '', ''
                
        return res
        
