import sys
import random
from random import randint

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class InteractiveJudge(object):
    def query(self, c, y, x):
        print c, y + 1, x + 1
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
            if odds and evens:
                if c == 1:
                    y, x = evens.pop()
                    self.judge.query(2, y, x)
                    matrix[y][x] = 2
                else:
                    y, x = odds.pop()
                    self.judge.query(1, y, x)
                    matrix[y][x] = 1
            elif odds:
                if c == 1:
                    y, x = odds.pop()
                    self.judge.query(3, y, x)
                    matrix[y][x] = 3
                else:
                    y, x = odds.pop()
                    self.judge.query(1, y, x)
                    matrix[y][x] = 1
            else:
                if c == 2:
                    y, x = evens.pop()
                    self.judge.query(3, y, x)
                    matrix[y][x] = 3
                else:
                    y, x = evens.pop()
                    self.judge.query(2, y, x)
                    matrix[y][x] = 2

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

j1 = TestJudge(2, ns=[1, 2, 1, 3])
s1 = Solution(j1)
assert s1.solve()

for i in xrange(10000):
    j3 = TestJudge(3, seed=i * i)
    s3 = Solution(j3)
    assert s3.solve()

j3 = TestJudge(10, seed=2469)
s3 = Solution(j3)
assert s3.solve()

j2 = TestJudge(20, seed=0)
s2 = Solution(j2)
assert s2.solve()

for i in xrange(2, 101):
    j3 = TestJudge(i, seed=199)
    s3 = Solution(j3)
    assert s3.solve()

# print 'ok'

j = InteractiveJudge()
s = Solution(j)
s.solve()
