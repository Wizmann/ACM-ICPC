MOD = (10 ** 9) + 7

KEYS = [-1, 
        -1, 3, 3, 
        3, 3, 3,
       4, 3, 4]

class Solution(object):
    def countTexts(self, pressedKeys):
        self.d = {}
        n = len(pressedKeys)
        return self.dfs(0, n, pressedKeys)
    
    def dfs(self, cur, n, keys):
        if cur == n:
            return 1
        
        if cur in self.d:
            return self.d[cur]
        
        cnt = 0
        res = 0
        maxi = KEYS[int(keys[cur])]
        for i in xrange(cur, n):
            if keys[i] == keys[cur]:
                cnt += 1
            else:
                break
            if cnt > maxi:
                break
            res += self.dfs(i + 1, n, keys)
        res %= MOD
        self.d[cur] = res
        return res
            
