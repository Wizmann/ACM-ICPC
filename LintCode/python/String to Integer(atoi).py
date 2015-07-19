import re

INT_MAX = (1 << 31) - 1
INT_MIN = -(1 << 31)

class Solution:
    # @param str: a string
    # @return an integer
    def atoi(self, str):
        str = str.strip()
        r = re.search("^[+-]?\d+", str)
        if not r:
            return 0
        str = r.group()
        res = int(str)
        res = min(INT_MAX, res)
        res = max(INT_MIN, res)
        return res
