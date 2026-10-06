class Solution(object):
    def minOperationsMaxProfit(self, customers, boardingCost, runningCost):
        maxi = -1
        maxv = 0
        cur = 0
        n = len(customers)
        customers.append(0)
        for i in xrange(n):
            c = min(4, customers[i])
            cur += c * boardingCost - runningCost
            # print i, cur
            if cur > maxv:
                maxv = cur
                maxi = i + 1
            if c < customers[i]:
                customers[i + 1] += customers[i] - c
        rem = customers[-1]
        cur += (rem / 4 * 4) * boardingCost - (rem / 4) * runningCost
        if cur > maxv:
            maxv = cur
            maxi = n + rem / 4
        cur += (rem % 4) * boardingCost - runningCost
        if cur > maxv:
            maxv = cur
            maxi = n + (rem + 3) / 4
        return maxi
        
