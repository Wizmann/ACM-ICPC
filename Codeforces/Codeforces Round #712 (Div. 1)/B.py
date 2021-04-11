import sys
import random
from random import randint

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class InteractiveJudge(object):
    def query(self, c, y, x):
        print c, y, x
        sys.stdout.flush()

    def read(self):
        return int(raw_input())

class TestJudge(object):
    def __init__(self, n, ns=[], seed=0):
        random.seed(seed)
        self.n = n
        if ns:
            self.ns = ns
        else:
            self.ns = [randint(1, 3) for i in xrange(self.n * self.n)]
        self.first = True

    def read(self):
        if self.first:
            self.first = False
            return self.n
        return self.ns.pop(0)

    def query(self, c, y, x):
        pass

class Solution(object):
    def __init__(self, judge):
        self.judge = judge

    def solve(self):
        self.n = self.judge.read()
        odds, evens = [], []
        matrix = [ [-1 for i in xrange(self.n)] for j in xrange(self.n) ]
        for i in xrange(self.n):
            for j in xrange(self.n):
                if (i + j) % 2 == 0:
                    evens.append((i, j))
                else:
                    odds.append((i, j))

        for i in xrange(self.n * self.n):
            c = self.judge.read()
            if c != 1:
                if odds:
                    (y, x) = odds.pop(0)
                    matrix[y][x] = 1
                    self.judge.query(1, y + 1, x + 1)
                else:
                    (y, x) = evens.pop(0)
                    matrix[y][x] = 5 - c
                    self.judge.query(5 - c, y + 1, x + 1)
            else:
                if evens:
                    (y, x) = evens.pop(0)
                    matrix[y][x] = 2
                    self.judge.query(2, y + 1, x + 1)
                else:
                    (y, x) = odds.pop(0)
                    matrix[y][x] = 3
                    self.judge.query(3, y + 1, x + 1)

        # print matrix
        for i in xrange(self.n):
            for j in xrange(self.n):
                for k in xrange(4):
                    ny = i + my[k]
                    nx = j + mx[k]
                    if ny < 0 or ny >= self.n or nx < 0 or nx >= self.n:
                        continue
                    assert matrix[i][j] != -1
                    if matrix[i][j] == matrix[ny][nx]:
                        return False
        return True

j = InteractiveJudge()
s = Solution(j)
s.solve()
