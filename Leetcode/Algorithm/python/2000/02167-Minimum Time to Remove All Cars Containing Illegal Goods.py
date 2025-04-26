INF = 10 ** 10

class Solution(object):
    def minimumTime(self, s):
        n = len(s)
        
        mini = n
        pre = 0
        for i in xrange(n - 1, -1, -1):
            cur = min(pre + 2 * int(s[i]), n - i)
            # print i, cur, pre
            mini = min(mini, cur + i)
            pre = cur
        return mini
            
