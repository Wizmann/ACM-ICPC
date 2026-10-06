class Solution(object):
    def minMoves(self, target, maxDoubles):
        res = 0
        while target != 1:
            if target % 2 == 0 and maxDoubles:
                res += 1
                target /= 2
                maxDoubles -= 1
            elif maxDoubles:
                res += 1
                target -= 1
            else:
                res += target - 1
                target = 1
        return res

''''
^^^TEST^^^^
5
0
------
4
$$$TEST$$$$

^^^^TEST^^^^
19
2
-----
7
$$$TEST$$$$

^^^TEST^^^^
10
4
------
4
$$$TEST$$$

^^^TEST^^^^
656101987
1
------
328050994
$$$TEST$$$
'''
