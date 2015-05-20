class Solution:
    # @param n: An integer.
    # return : A list of integer storing 1 to the largest number with n digits.
    def numbersByRecursion(self, n):
        return self.do_rec(1, n)
    
    def do_rec(self, ptr, n):
        if (ptr > n):
            return []
        a = 10 ** (ptr - 1)
        b = 10 ** ptr
        return range(a, b) + self.do_rec(ptr + 1, n)
