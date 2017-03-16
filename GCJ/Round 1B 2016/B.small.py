class Solution(object):
    def __init__(self, sa, sb):
        self.sa = sa
        self.sb = sb

    def solve(self):
        As = self.gen(self.sa)
        Bs = self.gen(self.sb)

        mini = 10 ** 20
        ans_a, ans_b = '', ''
        for item_a in As:
            for item_b in Bs:
                u = abs(int(item_a) - int(item_b))
                if u < mini:
                    mini = u
                    ans_a, ans_b = item_a, item_b
                elif u == mini:
                    if item_a < ans_a:
                        ans_a, ans_b = item_a, item_b
                    elif item_a == ans_a and item_b < ans_b:
                        ans_a, ans_b = item_a, item_b

        return ans_a, ans_b

    def gen(self, s):
        if not s:
            return ['']
        tmp = ''
        for i, c in enumerate(s):
            if c != '?':
                tmp += c
            else:
                t1 = map(str, range(0, 10))
                t2 = self.gen(s[i + 1:])

                res = []
                for item1 in t1:
                    for item2 in t2:
                        res.append(tmp + item1 + item2)
                return res
        return [tmp]

if __name__ == '__main__':
    assert Solution('1?', '2?').solve() == ('19', '20')
    assert Solution('?2?', '??3').solve() == ('023', '023')
    assert Solution('?', '?').solve() == ('0', '0')
    assert Solution('?5', '?0').solve() == ('05', '00')
    assert Solution('?8', '?1').solve() == ('08', '11')
    assert Solution('99', '?0').solve() == ('99', '90')

    T = int(raw_input())
    for i in xrange(T):
        a, b = raw_input().split()
        ans1, ans2 = Solution(a, b).solve()
        print 'Case #%d: %s %s' % (i + 1, ans1, ans2)



