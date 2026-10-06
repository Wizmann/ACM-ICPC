data = '''
# ...
'''
CHUNK = int(1e6)
answers = [0 for i in xrange(1001)]
for line in data.split('\n'):
    if not line.strip():
        continue
    a, b, c = map(int, line.split())
    answers[b / CHUNK] = c

for i in xrange(1, 1001):
    answers[i] += answers[i - 1]

class Solution(object):
    def beautifulNumbers(self, l, r):
        return self.solve(r) - self.solve(l - 1)

    def solve(self, x):
        if x == 0:
            return 0
        res = answers[(x - 1) / CHUNK]
        for i in xrange((x - 1) / CHUNK * CHUNK + 1, x + 1):
            ii = i
            m = 1
            s = 0
            while ii:
                m *= ii % 10
                s += ii % 10
                ii /= 10
                if m == 0:
                    break
            if m == 0 or m % s == 0:
                res += 1
        return res
