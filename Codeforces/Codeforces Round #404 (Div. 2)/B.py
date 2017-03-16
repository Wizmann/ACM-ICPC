class Solution(object):
    def __init__(self, As, Bs):
        self.As = As
        self.Bs = Bs

    def solve(self):
        return max(
                0, 
                self.do_solve(self.As, self.Bs), 
                self.do_solve(self.Bs, self.As))

    def do_solve(self, ns, ms):
        a = min(map(lambda (x, y): y, ns))
        b = max(map(lambda (x, y): x, ms))

        return b - a

def test():
    As = [
        (1, 5), 
        (2, 6), 
        (2, 3)
    ]

    Bs = [
        (2, 4),
        (6, 8),
    ]

    assert Solution(As, Bs).solve() == 3

    As = [
        (1, 5),
        (2, 6),
        (3, 7),
    ]

    Bs = [
        (2, 4),
        (1, 4),
    ]
    assert Solution(As, Bs).solve() == 0

if __name__ == '__main__':
    test()

    n = int(raw_input())
    As = []
    for i in xrange(n):
        p = map(int, raw_input().split())
        As.append(p)

    n = int(raw_input())
    Bs = []
    for i in xrange(n):
        p = map(int, raw_input().split())
        Bs.append(p)

    print Solution(As, Bs).solve()
