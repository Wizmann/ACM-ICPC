class CombinationIterator(object): 
    def __init__(self, characters, combinationLength):
        self.s = characters
        self.n = len(self.s)
        self.l = combinationLength
        self.ps = None

    def next(self):
        if not self.ps:
            self.ps = range(self.l)
        else:
            if not self.hasNext():
                return None

            q = self.l - 1
            while True:
                self.ps[q] += 1
                for i in xrange(q + 1, self.l):
                    self.ps[i] = self.ps[q] + (i - q)
                if self.ps[-1] < self.n:
                    break
                else:
                    q -= 1        

        res = ''
        for p in self.ps:
            res += self.s[p]
        return res

    def hasNext(self):
        if not self.ps:
            return True
        return self.ps[-1] != self.n - 1 or self.ps[0] != self.n - self.l


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
