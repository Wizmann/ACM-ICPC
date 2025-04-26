INF = 10 ** 10

class Solution(object):
    def minimumWhiteTiles(self, floor, numCarpets, carpetLen):
        self.d = {}
        self.carpetLen = carpetLen
        floor = map(int, floor)
        self.sufsum = floor[:]
        for i in xrange(len(floor) - 2, -1, -1):
            self.sufsum[i] += self.sufsum[i + 1]
        return self.dfs(0, floor, numCarpets)
    
    def dfs(self, cur, floor, num):
        while cur < len(floor) and floor[cur] == 0:
            cur += 1

        if cur >= len(floor):
            return 0

        if num == 0:
            return self.sufsum[cur]

        cc = cur
        key = (cur, num)
        if key in self.d:
            return self.d[key]
        mini = INF
        u = 0
        if num and floor[cur] == 1:
            mini = min(mini, u + self.dfs(cur + self.carpetLen, floor, num - 1))
        mini = min(mini, self.dfs(cur + 1, floor, num) + floor[cur])

        self.d[key] = mini
        return mini
            

'''
^^^TEST^^^
"0000"
1
1
------
0
$$$TEST$$$


^^^^^TEST^^^^
"10110101"
2
2
-------
2
$$$TEST$$$$

^^^^^TEST^^^^
"11111"
2
3
-------
0
$$$TEST$$$$

'''

        
