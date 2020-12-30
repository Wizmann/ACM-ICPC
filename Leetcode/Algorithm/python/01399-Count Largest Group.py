# https://leetcode.com/problems/count-largest-group/

from collections import defaultdict

def digitsum(x):
    return sum(map(int, str(x)))

class Solution:
    def countLargestGroup(self, n: int) -> int:
        d = defaultdict(int)
        for num in range(1, n + 1):
            d[digitsum(num)] += 1
        maxi = max(d.values())
        return list(d.values()).count(maxi)
