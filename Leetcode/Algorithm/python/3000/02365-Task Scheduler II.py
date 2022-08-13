from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def taskSchedulerII(self, tasks, space):
        d = {}
        today = 1
        for task in tasks:
            pre = d.get(task, -INF)
            today = max(today, pre + space + 1)
            d[task] = today
            # print today
            today += 1
        return today - 1
