INF = 10 ** 10

class Solution(object):
    def numberOfArrays(self, differences, lower, upper):
        mini, maxi = 0, 0

        cur = 0
        for item in differences:
            cur += item
            mini = min(mini, cur)
            maxi = max(maxi, cur)

        diff = lower - mini
        mini += diff
        maxi += diff
        print mini, maxi

        return max(0, upper - maxi + 1)

'''
^^^^TEST^^^
[1,-3,4]
1
6
-------
2
$$$TEST$$$$

^^^^TEST^^^
[3,-4,5,1,-2]
-4
5
-------
4
$$$TEST$$$$

^^^^TEST^^^
[4,-7,2]
3
6
-------
0
$$$TEST$$$$
'''
