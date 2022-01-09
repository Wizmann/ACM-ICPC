MOD = (10 ** 9) + 7

class Fancy(object):

    def __init__(self):
        self.premul = [1]
        self.preadd = [0]
        self.nums = []
        

    def append(self, val):
        self.premul.append(self.premul[-1])
        self.preadd.append(self.preadd[-1])
        self.nums.append(val)
        

    def addAll(self, inc):
        self.preadd[-1] += inc
        

    def multAll(self, m):
        self.preadd[-1] = self.preadd[-1] * m % MOD
        self.premul[-1] = self.premul[-1] * m % MOD
        

    def getIndex(self, idx):
        if idx >= len(self.nums):
            return -1
        mul = self.premul[-1] * pow(self.premul[idx], MOD - 2, MOD)
        add = self.preadd[-1] - self.preadd[idx] * mul
        return (self.nums[idx] * mul + add) % MOD


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
