# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b3034

def solve(strs):
    n = len(strs)

    segs = []
    maxi = 0
    for i in xrange(n):
        s = '^' + strs[i] + '$'
        cur = ''
        m = len(s)
        seg = []
        j = 0
        while j < m:
            if s[j] != '*':
                cur += s[j]
                j += 1
            else:
                cur += '*'
                seg.append(cur)
                cur = '*'
                j += 1
        if cur:
            seg.append(cur)
        maxi = max(maxi, len(seg))
        segs.append(seg)

    # print segs

    for i in xrange(n):
        while len(segs[i]) < maxi:
            segs[i] = [segs[i][0]] + ["**"] + segs[i][1:]

    res = ''
    for i in xrange(maxi):
        pres = ['']
        for j in xrange(n):
            s = segs[j][i]
            if s[0] != '*':
                if s[-1] == '*':
                    pres.append(s[:-1])
                else:
                    pres.append(s)
        # print 'pres', pres
        pre = max(pres, key=lambda s: len(s))
        for p in pres:
            if not pre.startswith(p):
                return '*'

        sufs = ['']
        for j in xrange(n):
            s = segs[j][i]
            if s[-1] != '*':
                if s[0] == '*':
                    sufs.append(s[1:])
                else:
                    sufs.append(s)
        # print 'sufs', sufs
        suf = max(sufs, key=lambda s: len(s))
        for s in sufs:
            if not suf.endswith(s):
                return '*'

        mid = ''
        for j in xrange(n):
            s = segs[j][i]
            if s[0] == '*' and s[-1] == '*':
                mid += s[1: -1]
        # print 'mid', mid
        res += pre + mid + suf
        # print res

    # print res
    return res[1:-1]

class Matching(object):
    def __init__(self, pattern, word):
        self.pattern = pattern
        self.word = word
        self.d = {}

    def match(self):
        return self.do_match(0, 0)

    def do_match(self, p, q):
        if (p, q) in self.d:
            return self.d[(p, q)]

        if p == len(self.pattern) and q == len(self.word):
            return True
        pc = '' if p == len(self.pattern) else self.pattern[p]
        qc = '' if q == len(self.word) else self.word[q]

        res = False
        if pc == qc:
            res = self.do_match(p + 1, q + 1)
        elif pc == '*':
            while q <= len(self.word):
                res = self.do_match(p + 1, q)
                q += 1
                if res:
                    break
        else:
            res = False

        self.d[(p, q)] = res
        return res
    
assert Matching("*FOO", "FOO").match()
assert not Matching("*FOO", "FOOBAR").match()

def test(patterns):
    word = solve(patterns)

    assert len(word) < 10000

    for pattern in patterns:
        if not Matching(pattern, word).match():
            return False
    return True


T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    strs = [raw_input() for i in xrange(n)]

    print 'Case #%d: %s' % (case_ + 1, solve(strs))
