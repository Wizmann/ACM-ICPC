from random import randint

class Solution(object):

    def __init__(self, n_rows, n_cols):
        self.n = n_rows
        self.m = n_cols
        self.mat = set()

    def flip(self):
        while True:
            idx = randint(0, self.n * self.m - 1)
            if idx not in self.mat:
                self.mat.add(idx)
                break
        return (idx / self.m, idx % self.m)

    def reset(self):
        self.mat = set()

# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
