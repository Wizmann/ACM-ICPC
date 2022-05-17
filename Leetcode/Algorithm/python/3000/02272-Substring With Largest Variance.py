from collections import deque
from string import ascii_lowercase

class Solution(object):
    def largestVariance(self, s):
        res = 0
        st = set(s)
        for c1 in ascii_lowercase:
            for c2 in ascii_lowercase:
                if c1 != c2 and c1 in st and c2 in st:
                    res = max(res, self.solve(s, c1, c2))
        return res
    
    def solve(self, s, c1, c2):
        tot = 0
        res = 0
        u1, u2 = 0, 0
        for c in s:
            if c not in [c1, c2]:
                continue

            if c == c1:
                u1 += 1
            elif c == c2:
                u2 += 1

            u = 1 if c == c1 else -1
            tot += u

            if u1 and u2:
                res = max(res, tot)
            elif u1:
                res = max(res, tot - 1)

            if tot < 0:
                tot = 0
                u1, u2 = 0, 0

        return res



'''

^^^TEST^^^
"aababbb"
----
3
$$$TEST$$$

^^^TEST^^^
"abcde"
----
0
$$$TEST$$$

^^^^TEST^^^
"lripaa"
------
1
$$$TEST$$$

^^^TEST^^^
"bbc"
-------
1
$$$TEST$$$

^^^TEST^^^
"ykudzhiixwttnvtesiwnbcjmsydidttiyabbwzlfbmmycwjgzwhbtvtxyvkkjgfehaypiygpstkhakfasiloaveqzcywsiujvixcdnxpvvtobxgroznswwwipypwmdhldsoswrzyqthaqlbwragjrqwjxgmftjxqugoonxadazeoxalmccfeyqtmoxwbnphxih"
-------
12
$$$TEST$$$

^^^^TEST^^^
"ngnngggggnggggggg"
------
11
$$$TEST$$$

^^^TEST^^^
"clnmgztqeutmubhkdddahzzwqmmfppvsirjvtevxbfcnezhasmzvbjunohqpzymrrvdsgoetegdkwzvgtqavbetctjscgihphmbadglnygxvljeesqkicodpmzfzbpyqvglqoyzqollgcmbpcpeigukgyyjhbacckhzxckwdlayzspkrlgwjauoehoeptrxeygofztspjxpsdf"
------
11
$$$TEST$$$


^^^TEST^^^
"dsyemilsuwhciclqwprizywgkwkbgcqhtcwfvlw"
------
5
$$$TEST$$$

^^^TEST^^^
"sswwwwww"
------
5
$$$TEST$$$

'''

        
