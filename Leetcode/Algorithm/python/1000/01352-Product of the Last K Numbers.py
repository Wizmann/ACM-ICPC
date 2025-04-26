# https://leetcode.com/problems/product-of-the-last-k-numbers/submissions/

class ProductOfNumbers:

    def __init__(self):
        self.ns = []

    def add(self, num: int) -> None:
        if num == 0:
            self.ns = []
            return
        if not self.ns:
            self.ns.append(num)
        else:
            self.ns.append(num * self.ns[-1])
        # assert 0 not in self.ns

    def getProduct(self, k: int) -> int:
        if k > len(self.ns):
            return 0
        elif k == len(self.ns):
            return self.ns[-1]
        else:
            return self.ns[-1] // self.ns[len(self.ns) - k - 1]
        
################

class ProductOfNumbers:
    def __init__(self):
        self.ns = []
        self.batch = []
        self.BATCH = 100
        self.tail = 1

    def add(self, num: int) -> None:
        self.ns.append(num)
        self.tail *= num
        if len(self.ns) % self.BATCH == 0:
            self.batch.append(self.tail)
            self.tail = 1

    def getProduct(self, k: int) -> int:
        l = len(self.ns) - k
        r = len(self.ns) - 1
        res = 1
        while r >= l and (r + 1) % self.BATCH != 0:
            res *= self.ns[r]
            r -= 1
        while r - self.BATCH >= l:
            res *= self.batch[r // self.BATCH]
            r -= self.BATCH
        while r >= l:
            res *= self.ns[r]
            r -= 1
        return res        
