INF = 10 ** 10

class Solution(object):
    def minCostConnectPoints(self, points):
        n = len(points)
        dis = [INF for i in xrange(n)]
        dis[0] = 0
        visited = [False for i in xrange(n)]

        res = 0
        for i in xrange(n):
            minv = INF
            minp = -1
            for j in xrange(n):
                if not visited[j] and dis[j] < minv:
                    minv = dis[j]
                    minp = j
            visited[minp] = True
            res += minv
            for j in xrange(n):
                dis[j] = min(dis[j], abs(points[j][0] - points[minp][0]) + \
                                     abs(points[j][1] - points[minp][1]))
        return res


points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
assert Solution().minCostConnectPoints(points) == 20

points = [[-1000000,-1000000],[1000000,1000000]]
assert Solution().minCostConnectPoints(points) == 4000000

