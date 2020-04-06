import sys
import random

DEBUG = True

def logging(*args):
    if not DEBUG:
        return
    lineno = sys._getframe(1).f_lineno
    sys.stderr.write("L%d: " % lineno)
    for arg in args:
        sys.stderr.write("%s " % str(arg))
    sys.stderr.write("\n")
    sys.stderr.flush()

def pprint(line):
    pline = map(lambda x: 'x' if x == -1 else str(x), line)
    return ''.join(pline)

def countEmpty(line):
    return len(filter(lambda x: x == -1, line))

def findEmpty(line):
    n = len(line)
    for i in xrange(n):
        if line[i] == -1:
            return i
    return -1

def flip(line):
    n = len(line)
    for i in xrange(n):
        if line[i] == -1:
            continue
        else:
            line[i] = line[i] ^ 1
    return line

def reverse(line):
    return line[::-1]

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
    def __init__(self, bits, seed=0):
        self.bits = map(int, bits)
        self.cnt = 0
        random.seed(seed)

    def query(self, line):
        line = str(line)
        if len(line) == len(self.bits):
            #print ''.join(line)
            #print ''.join(map(str, self.bits))
            if map(int, line) == self.bits:
                return "Y"
            else:
                return "N"
        else:
            self.cnt += 1
            if self.cnt > 150:
                assert False
            if self.cnt % 10 == 1:
                r = random.randint(1, 4)
                origin = self.bits[:]
                # print r
                if r == 1:
                    self.bits = flip(self.bits)
                elif r == 2:
                    self.bits = reverse(self.bits)
                elif r == 3:
                    self.bits = flip(reverse(self.bits))
                else:
                    pass
                self.r = r
            p = int(line)
            return str(self.bits[p - 1])

class Solution(object):
    def __init__(self, B, judge):
        self.B = B
        self.judge = judge

    def solve(self):
        cnt = 0
        bits = [-1 for i in xrange(self.B)]

        p, q = 0, self.B  - 1
        a1, b1 = -1, -1
        while countEmpty(bits):
            st = set([1, 2, 3, 4])
            if a1 != -1:
                u = int(self.judge.query(a1 + 1))
                cnt += 1
                if u != bits[a1]:
                    st &= set([1, 3])
                else:
                    st &= set([2, 4])
            if b1 != -1:
                u = int(self.judge.query(b1 + 1))
                cnt += 1
                if u != bits[b1]:
                    st &= set([1, 2])
                else:
                    st &= set([3, 4])

            if cnt % 2 != 0:
                _ = int(self.judge.query(1))
                cnt += 1

            if a1 != -1 or b1 != -1:
                c = list(st)[0]
                if c == 1:
                    bits = flip(bits)
                elif c == 2:
                    bits = reverse(bits)
                elif c == 3:
                    bits = flip(reverse(bits))
                else:
                    assert c == 4

            while cnt == 0 or cnt % 10 != 0:
                l = findEmpty(bits)
                if l == -1:
                    break
                r = self.B - 1 - l
                u = int(self.judge.query(l + 1))
                cnt += 1
                v = int(self.judge.query(r + 1))
                cnt += 1
                if u == v and a1 == -1:
                    a1 = l
                elif u != v and b1 == -1:
                    b1 = l
                bits[l], bits[r] = u, v
        logging(pprint(bits))
        # logging(pprint(self.judge.bits))
        res = self.judge.query(''.join(map(str, bits)))
        assert res in 'YN'
        if res == 'N':
            assert False

for i in xrange(300):
    s = Solution(20, TestJudge('01001101101101110010', i))
    s.solve()
for i in xrange(300):
    s = Solution(10, TestJudge('1111111111', i))
    s.solve()
for i in xrange(300):
    s = Solution(10, TestJudge('1111100000', i))
    s.solve()
for i in xrange(30):
    s = Solution(100, TestJudge('1' * 50 + '0' * 50, i))
    s.solve()
for i in xrange(30):
    s = Solution(100, TestJudge('1011111001111011110001000010010000001101010101101000101000011011000000001101101010101101111001000010', i))
    s.solve()
for i in xrange(300):
    s = Solution(10, TestJudge('1010110101', i))
    s.solve()

T, B = map(int, raw_input().split())

for case_ in xrange(T):
    s = Solution(B, InteractiveJudge())
    s.solve()

