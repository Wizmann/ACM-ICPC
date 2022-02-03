class Solution(object):
    def minimumCost(self, cost):
        cost.sort()
        res = 0
        while cost:
            if len(cost) >= 3:
                items = cost[-3:]
                cost = cost[:-3]
            else:
                items = cost
                cost = []
            
            if len(items) == 3:
                res += items[-1] + items[-2]
            else:
                res += sum(items)
        return res

'''
^^^TEST^^^
[1,2,3]
-------
5
$$$TEST$$$

^^^TEST^^^
[6,5,7,9,2,2]
-------
23
$$$TEST$$$

^^^TEST^^^
[5, 5]
-------
10
$$$TEST$$$

^^^TEST^^^
[5]
-------
5
$$$TEST$$$

'''

