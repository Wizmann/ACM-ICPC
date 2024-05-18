#python2
class MyCounter(object):
    def __init__(self):
        self.cnt = {}
        self.mp = {}

    def insert(self, c):
        pre = self.mp.get(c, 0)
        if pre:
            self.cnt[pre] -= 1
            if self.cnt[pre] == 0:
                del self.cnt[pre]
        cur = pre + 1
        self.mp[c] = cur
        self.cnt[cur] = self.cnt.get(cur, 0) + 1

    def get_cnt(self):
        return len(self.cnt)

INF = 10 ** 100

class Solution(object):
    def minimumSubstringsInPartition(self, s):
        n = len(s)
        dp = [INF for i in xrange(n + 1)]

        dp[0] = 0
        for i in xrange(1, n + 1):
            counter = MyCounter()
            for j in xrange(i, 0, -1):
                counter.insert(s[j - 1])
                if counter.get_cnt() == 1:
                    dp[i] = min(dp[i], dp[j - 1] + 1)
        return dp[-1]

# print Solution().minimumSubstringsInPartition("aaa")

'''

^^^^TEST^^^^
"fabccddg"
----------
3
$$$$TEST$$$$

^^^^TEST^^^^
"abababaccddb"
----------
2
$$$$TEST$$$$

^^^^TEST^^^^
"aaaaaa"
----------
1
$$$$TEST$$$$

'''
        
