class Solution(object):
    def lastRemaining(self, n):
        fs = []
        cnt = 0
        while n > 1:
            if cnt % 2 == 0 or (cnt % 2 != 0 and n % 2 != 0):
                n /= 2
                fs.append(lambda x: x * 2)
            else:
                n = (n + 1) / 2
                fs.append(lambda x: x * 2 - 1)
            #print n
            cnt += 1
        res = 1
        for f in fs[::-1]:
            res = f(res)
        return res
