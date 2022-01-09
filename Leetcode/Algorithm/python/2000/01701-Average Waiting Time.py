class Solution(object):
    def averageWaitingTime(self, customers):
        t = 0
        w = 0
        n = len(customers)
        for (arr, prepare) in customers:
            t = max(t, arr)
            w += t - arr + prepare
            # print t - arr + prepare
            t += prepare
        return 1.0 * w / n
