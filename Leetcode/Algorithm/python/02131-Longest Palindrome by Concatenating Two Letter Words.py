from collections import defaultdict
from collections import Counter

class Solution(object):
    def longestPalindrome(self, words):
        d = defaultdict(int)
        c = Counter(words)

        res = 0
        mid = 0

        for word, count in sorted(c.items()):
            rev = word[::-1]
            if rev > word:
                continue
            elif rev == word:
                res += len(word) * (count / 2 * 2)
                if count % 2 == 1:
                    mid = max(mid, len(word))
            else:
                res += min(count, c[rev]) * len(word) * 2
        return res + mid

'''
^^^TEST^^^
["lc","cl","gg"]
------
6
$$$TEST$$$$

^^^TEST^^^
["ab","ty","yt","lc","cl","ab"]
------
8
$$$TEST$$$$

^^^TEST^^^
["cc","ll","xx"]
------
2
$$$TEST$$$$
'''

        
