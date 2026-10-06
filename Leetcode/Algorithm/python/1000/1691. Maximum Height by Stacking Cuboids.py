class Solution(object):
    def maxHeight(self, cuboids):
        items = []
        for i, (a, b, c) in enumerate(cuboids):
            a, b, c = sorted([a, b, c])
            items.append((a, b, c, i))
        items.sort()
        n = len(items)
        dp = [0 for i in xrange(n)]
        
        for i, item in enumerate(items):
            w1, l1, h1, idx1 = item
            dp[i] = h1

            for j in xrange(i):
                w2, l2, h2, idx2 = items[j]
                if idx1 == idx2 or l1 < l2 or h1 < h2 or dp[j] + h1 < dp[i]:
                    continue
                dp[i] = max(dp[i], dp[j] + h1)
                
        return max(dp)
                    
