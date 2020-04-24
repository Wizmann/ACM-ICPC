# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b63

import sys
import random
from random import randint

DEBUG = False

def logging(*args):
    if not DEBUG:
        return
    lineno = sys._getframe(1).f_lineno
    sys.stderr.write("L%d: " % lineno)
    for arg in args:
        sys.stderr.write("%s " % str(arg))
    sys.stderr.write("\n")
    sys.stderr.flush()

N = 10 ** 9

class IJudge(object):
    def query(self, line):
        pass

class InteractiveJudge(object):
    def query(self, line):
        print line
        sys.stdout.flush()
        res = raw_input().strip()
        if res == 'N':
            sys.exit(0)
        return res


class TestJudge(object):
    def __init__(self, rA, rB, seed=0):
        random.seed(seed)
        self.r = random.randint(rA, rB)
        self.y = random.randint(-N + self.r, N - self.r)
        self.x = random.randint(-N + self.r, N - self.r)
        logging(self.x, self.y)

    def query(self, line):
        x, y = map(int, line.split())
        if x == self.x and y == self.y:
            return 'CENTER'
        dis = (x - self.x) ** 2 + (y - self.y) ** 2
        if dis > self.r ** 2:
            return 'MISS'
        return 'HIT'

class Solution(object):
    def __init__(self, n1, n2, judge):
        self.n1 = n1
        self.n2 = n2
        self.judge = judge

    def solve(self):
        res = ''
        self.center = None
        while res not in ['CENTER', 'HIT']:
            y = randint(-N, N)
            x = randint(-N, N)

            res = self.query(x, y)

            if res == 'CENTER':
                self.center = (x, y)

            if res == 'HIT':
                break

        if self.center:
            return

        logging(x, y, self.query(x, y))

        cx = self.query_x(y, x)
        if self.center:
            return

        cy = self.query_y(x, y)
        if self.center:
            return

        logging(cx, cy, self.query(cx, cy))

        # assert self.query(cx, cy) == 'CENTER'
        logging(cx, cy)
        

    def query(self, x, y):
        line = '%d %d' % (x, y)
        return self.judge.query(line)

    def query_x(self, y, x):
        l, r = -N, x
        while l <= r:
            m = (l + r) / 2
            res = self.query(m, y)
            if res == 'CENTER':
                self.center = (m, y)
                return N
            if res == 'MISS':
                l = m + 1
            else:
                r = m - 1
        lx = l

        l, r = x, N
        while l <= r:
            m = (l + r) / 2
            res = self.query(m, y)
            if res == 'CENTER':
                self.center = (m, y)
                return N
            if res == 'HIT':
                l = m + 1
            else:
                r = m - 1
        rx = r

        assert (lx + rx) % 2 == 0
        return (lx + rx) / 2

    def query_y(self, x, y):
        l, r = -N, y
        while l <= r:
            m = (l + r) / 2
            res = self.query(x, m)
            if res == 'CENTER':
                self.center = (x, m)
                return N
            if res == 'MISS':
                l = m + 1
            else:
                r = m - 1
        ly = l

        l, r = y, N
        while l <= r:
            m = (l + r) / 2
            res = self.query(x, m)
            if res == 'CENTER':
                self.center = (x, m)
                return N
            if res == 'HIT':
                l = m + 1
            else:
                r = m - 1
        ry = r

        assert (ly + ry) % 2 == 0
        return (ly + ry) / 2

N1 = (10 ** 9) - 5
Solution(N1, N1, TestJudge(N1, N1, 4)).solve()
for i in xrange(1000):
    logging(i)
    N1 = (10 ** 9) - 5
    Solution(N1, N1, TestJudge(N1, N1, i)).solve()
N2 = (10 ** 9) - 50
for i in xrange(1000):
    logging(i)
    N2 = (10 ** 9) - 5
    Solution(N2, N2, TestJudge(N2, N2, i)).solve()
# print 'ok'


T, A, B = map(int, raw_input().split())

for case_ in xrange(T):
    s = Solution(A, B, InteractiveJudge())
    s.solve()

