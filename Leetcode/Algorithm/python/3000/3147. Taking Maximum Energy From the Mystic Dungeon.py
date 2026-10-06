INF = 10 ** 100
class Solution(object):
    def maximumEnergy(self, energy, k):
        maxi = -INF
        n = len(energy) - 1
        for i in xrange(k):
            cur = n - i
            tot = 0
            while cur >= 0:
                tot += energy[cur]
                maxi = max(maxi, tot)
                cur -= k
        return maxi

'''
^^^^^TEST^^^^
[5,2,-10,-5,1]
3
------------
3
$$$$$$TEST$$$$$

^^^^^TEST^^^^
[-2,-3,-1]
2
------------
-1
$$$$$$TEST$$$$$

^^^^^TEST^^^^
[-2,-3,-1]
1
------------
-1
$$$$$$TEST$$$$$

'''

