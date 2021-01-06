class Solution(object):
    def minCost(self, s, cost):
        cost.append(0)
        s += '$'
        l, r = -1, -1
        pre = '^'
        res = 0
        for i, c in enumerate(s):
            if c == pre:
                r = i
            else:
                if l == -1 and r == -1:
                    pass
                elif r - l + 1 > 1:
                    res += sum(cost[l: r + 1]) - max(cost[l: r + 1])
                l = i
                r = i
                pre = c
        return res
