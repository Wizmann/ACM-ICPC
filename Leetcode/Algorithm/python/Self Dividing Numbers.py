class Solution(object):
    def selfDividingNumbers(self, left, right):
        res = []
        for i in xrange(left, right + 1):
            if self.judge(i):
                res.append(i)
        return res
    
    def judge(self, n):
        for item in map(int, str(n)):
            if item == 0:
                return False
            if n % item != 0:
                return False
        return True
