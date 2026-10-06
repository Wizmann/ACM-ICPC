class Solution(object):
    def successfulPairs(self, spells, potions, success):
        n = len(spells)
        potions.sort()
        spells = sorted(enumerate(spells), key=lambda x: -x[1])

        ptr = 0
        res = [0 for i in xrange(n)]
        for i, spell in spells:
            while ptr < len(potions) and spell * potions[ptr] < success:
                ptr += 1

            res[i] = len(potions) - ptr
        return res

'''
^^^^^TEST^^^^
[5,1,3]
[1,2,3,4,5]
7
--------------
[4, 0, 3]
$$$$$TEST$$$$$

^^^^^TEST^^^^
[3,1,2]
[8,5,8]
16
--------------
[2, 0, 2]
$$$$$TEST$$$$$
'''

