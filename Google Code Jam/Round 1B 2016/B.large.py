class Solution(object):
    def __init__(self, sa, sb):
        self.sa = sa
        self.sb = sb
        self.n = len(sa)

    def solve(self):
        ans = self.dfs(0)
        mini = 10 ** 20
        resa, resb = '', ''
        for item in ans:
            _, a, b = item
            if not a or not b:
                continue
            if abs(int(a) - int(b)) < mini:
                resa, resb = a, b
                mini = abs(int(a) - int(b))
            elif abs(int(a) - int(b)) == mini:
                if a < resa:
                    resa, resb = a, b
                elif a == resa and b < resb:
                    resa, resb = a, b
        return resa, resb

    def dfs(self, cur):
        if cur == self.n:
            return [(0, '', '')]

        nxt = self.dfs(cur + 1)

        a = self.sa[cur]
        b = self.sb[cur]

        mini = (10 ** 20 , str(10 ** 20), str(20 ** 20))
        ans1 = (-10 ** 20, str(10 ** 20), str(20 ** 20))
        ans2 = (10 ** 20 , str(10 ** 20), str(20 ** 20))
        maxi = (-10 ** 20, str(10 ** 20), str(20 ** 20))

        base = 10 ** (self.n - cur - 1)
        res = []

        As = [int(a)] if a != '?' else range(10)
        Bs = [int(b)] if b != '?' else range(10)

        for ia in As:
            for ib in Bs:
                for item in nxt:
                    v, s1, s2 = (ia - ib) * base + item[0], str(ia) + item[1], str(ib) + item[2]

                    if v > maxi[0]:
                        maxi = (v, s1, s2)
                    elif v == maxi[0]:
                        if int(s1) < int(maxi[1]):
                            maxi = (v, s1, s2)
                        elif int(s1) == int(maxi[1]) and int(s2) < int(maxi[2]):
                            maxi = (v, s1, s2)


                for item in nxt:
                    v, s1, s2 = (ia - ib) * base + item[0], str(ia) + item[1], str(ib) + item[2]

                    if v < mini[0]:
                        mini = (v, s1, s2)
                    elif v == mini[0]:
                        if int(s1) < int(mini[1]):
                            mini = (v, s1, s2)
                        elif int(s1) == int(mini[1]) and int(s2) < int(mini[2]):
                            mini = (v, s1, s2)

                for item in nxt:
                    v, s1, s2 = (ia - ib) * base + item[0], str(ia) + item[1], str(ib) + item[2]

                    if v <= 0 and v > ans1[0]:
                        ans1 = (v, s1, s2)
                    elif v == ans1[0]:
                        if int(s1) < int(ans1[1]):
                            ans1 = (v, s1, s2)
                        elif int(s1) == int(ans1[1]) and int(s2) < int(ans1[2]):
                            ans1 = (v, s1, s2)

                for item in nxt:
                    v, s1, s2 = (ia - ib) * base + item[0], str(ia) + item[1], str(ib) + item[2]

                    if v >= 0 and v < ans2[0]:
                        ans2 = (v, s1, s2)
                    elif v == ans2[0]:
                        if int(s1) < int(ans2[1]):
                            ans2 = (v, s1, s2)
                        elif int(s1) == int(ans2[1]) and int(s2) < int(ans2[2]):
                            ans2 = (v, s1, s2)

        return filter(lambda x: abs(x[0]) < 10 ** 20, [mini, ans1, ans2, maxi])

if __name__ == '__main__':
    assert Solution('0?3', '2?9').solve() == ('093', '209')
    assert Solution('1?', '2?').solve() == ('19', '20')
    assert Solution('?2?', '??3').solve() == ('023', '023')
    assert Solution('?', '?').solve() == ('0', '0')
    assert Solution('?5', '?0').solve() == ('05', '00')
    assert Solution('?8', '?1').solve() == ('08', '11')
    assert Solution('99', '?0').solve() == ('99', '90')

    T = int(raw_input())
    for case_ in xrange(T):
        a, b = raw_input().split()
        sa, sb = Solution(a, b).solve()
        print 'Case #%d: %s %s' % (case_ + 1, sa, sb)
