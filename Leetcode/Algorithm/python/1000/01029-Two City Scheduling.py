class Solution(object):
    def twoCitySchedCost(self, costs):
        n = len(costs)
        costs.sort(key=lambda (x, y): x - y)
        return sum(map(lambda x: x[0], costs[:n / 2]) + map(lambda x: x[1], costs[n / 2:]))
