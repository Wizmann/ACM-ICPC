class Solution(object):
    def findComplement(self, num):
        p = num
        while (num & (num + 1)) != 0:
            num |= num >> 1
        return p ^ num
        

assert Solution().findComplement(1) == 0
assert Solution().findComplement(5) == 2
assert Solution().findComplement(7) == 0
assert Solution().findComplement(8) == 7
