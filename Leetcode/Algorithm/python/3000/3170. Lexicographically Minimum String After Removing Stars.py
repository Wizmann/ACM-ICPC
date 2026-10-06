import string
from collections import defaultdict
class Solution(object):
    def clearStars(self, s):
        d = defaultdict(list)

        for i, c in enumerate(s):
            if c == '*':
                for pre in string.ascii_lowercase:
                    if d[pre]:
                        d[pre].pop()
                        break
            else:
                d[c].append(i)

        res = []
        for c in string.ascii_lowercase:
            for pos in d[c]:
                res.append((pos, c))
        res.sort()
        return ''.join(map(lambda x: x[1], res))

'''

^^^^TEST^^^
"aaba*"
---------
"aab"
$$$TEST$$$

^^^^TEST^^^
"abc"
---------
"abc"
$$$TEST$$$

^^^^TEST^^^
"ab*c"
---------
"bc"
$$$TEST$$$


'''
