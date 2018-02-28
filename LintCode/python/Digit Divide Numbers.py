class Solution:
    """
    @param lower: Integer : lower bound
    @param upper: Integer : upper bound
    @return: a list of every possible Digit Divide Numbers
    """
    def digitDivideNums(self, lower, upper):
        res = []
        for i in xrange(lower, upper + 1):
            u = i
            while u:
                num = u % 10
                u /= 10
                if num == 0 or i % num != 0:
                    break
            else:
                res.append(i)
        return res
