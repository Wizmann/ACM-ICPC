class Solution(object):
    def average(self, salary):
        tot = sum(salary) - min(salary) - max(salary)
        return 1.0 * tot / (len(salary) - 2)
