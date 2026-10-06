INF = 19 ** 19

fives = set([5 ** i for i in xrange(64)])

class Solution(object):
    def minimumBeautifulSubstrings(self, s):
        s = map(int, s)
        n = len(s)
        self.d = {}
        ans = self.dfs(0, n, s, 0)
        if ans == INF:
            return -1
        return ans

    def dfs(self, cur, n, s, num):
        if cur == n:
            return 0 if num == 0 else INF
        if num == 0 and s[cur] == 0:
            return INF
        key = (cur, num)
        if key in self.d:
            return self.d[key]
        num = num * 2 + s[cur]
        res = INF
        if num in fives:
            res = min(res, self.dfs(cur + 1, n, s, 0) + 1)
        res = min(res, self.dfs(cur + 1, n, s, num))
        self.d[key] = res
        return res
        

'''
^^^^TEST^^^
"1011"
-------
2
$$$$TEST$$$$

^^^^TEST^^^
"111"
-------
3
$$$$TEST$$$$

^^^^TEST^^^
"0"
-------
-1
$$$$TEST$$$$
'''
