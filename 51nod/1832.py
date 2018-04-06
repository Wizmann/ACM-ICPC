class Solution(object):
    def __init__(self, a, b):
        self.da = dict(map(lambda (i, item): (item, i), enumerate(a)))
        self.db = dict(map(lambda (i, item): (item, i), enumerate(b)))
        self.a = a
        self.b = b

    def solve(self, la, ra, lb, rb):
        assert ra - la == rb - lb
        assert self.a[la] == self.b[rb]

        if la == ra and lb == rb:
            return 1

        la += 1
        rb -= 1


        rootl = self.a[la]
        idx = self.db[rootl]
        count = idx - lb + 1

        vl = self.solve(la, la + count - 1, lb, idx)
        if la + count <= ra and idx + 1 <= rb:
            vr = self.solve(la + count, ra, idx + 1, rb)
            return vl * vr
        else:
            return 2 * vl


if __name__ == '__main__':
    n = int(raw_input())
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    
    print Solution(a, b).solve(0, n - 1, 0, n - 1)
