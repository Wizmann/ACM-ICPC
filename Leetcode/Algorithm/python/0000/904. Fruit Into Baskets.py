class Solution(object):
    def totalFruit(self, tree):
        d = {}
        n = len(tree)
        
        l, r = 0, 0
        
        ans = 0
        while l < n and r < n:
            cur = tree[r]
            d[cur] = d.get(cur, 0) + 1
            
            while len(d) > 2:
                pre = tree[l]
                d[pre] -= 1
                if d[pre] == 0:
                    del d[pre]
                l += 1
            ans = max(ans, sum(d.values()))
            r += 1
        return ans
