INF = 10 ** 10

class Solution(object):
    def minCostSetTime(self, startAt, moveCost, pushCost, targetSeconds):
        mins = targetSeconds / 60
        secs = targetSeconds % 60
        mincost = INF
        while mins >= 0 and secs <= 99:
            if mins < 100:
                if mins:
                    t = map(int, "%d%02d" % (mins, secs))
                else:
                    t = map(int, str(secs))
                cur = startAt
                cost = 0
                for c in t:
                    if c != cur:
                        cost += moveCost
                        cur = c
                    cost += pushCost
                mincost = min(mincost, cost)
                # print t, cost
            secs += 60
            mins -= 1
        return mincost
                
