class Bitset(object):

    def __init__(self, size):
        self.size = size
        self.sum = 0
        self.bits = [0 for i in xrange(self.size)]
        self.flag = 0

    def fix(self, idx):
        value = 1 ^ self.flag
        if value != self.bits[idx]:
            self.sum += 1
            self.bits[idx] ^= 1
        

    def unfix(self, idx):
        value = 0 ^ self.flag
        if value != self.bits[idx]:
            self.sum -= 1
            self.bits[idx] ^= 1
        

    def flip(self):
        self.flag ^= 1
        self.sum = self.size - self.sum
        

    def all(self):
        return self.sum == self.size

    def one(self):
        return self.sum > 0

    def count(self):
        return self.sum
        

    def toString(self):
        return ''.join(map(lambda x : str(x ^ self.flag), self.bits))
        


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()
