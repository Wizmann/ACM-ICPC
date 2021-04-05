class OrderedStream(object):

    def __init__(self, n):
        self.n = n
        self.slots = [None for i in xrange(n)]
        self.ptr = 0
        
    def insert(self, idKey, value):
        idKey -= 1
        self.slots[idKey] = value
        res = []
        while self.ptr < self.n and self.slots[self.ptr]:
            res.append(self.slots[self.ptr])
            self.ptr += 1
        return res


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
