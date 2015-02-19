MOD = 1000000000 + 7

def do_hash(s):
    h = 0

    for c in s[::-1]:
        h = h * 3 + ord(c) - ord('a')
        h %= MOD

    return h

if __name__ == '__main__':
    (n, m) = map(int, raw_input().split())
    d = {}
    for i in xrange(n):
        s = raw_input()
        h = do_hash(s)
        d[h] = d.get(h, [])
        d[h].append((len(s), s))

    for i in xrange(m):
        try:
            s = raw_input()
            lens = len(s)
            h = do_hash(s)

            u = 1
            for idx, c in enumerate(s):
                v = ord(c) - ord('a')
                hh = ((h - v * u) % MOD + MOD) % MOD
                for i in xrange(3):
                    if i == v:
                        continue
                    hhh = (hh + i * u) % MOD
                    if hhh in d:
                        sss = s[:idx] + chr(i + ord('a')) + s[idx + 1:]
                        for (l, ss) in d[hhh]:
                            if ss == sss:
                                raise 'done'
                u = (u * 3) % MOD
            print 'NO'
        except:
            print 'YES'
