MOD = 10 ** 9 + 7

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),
        n = int(raw_input())

        ns = map(int, raw_input().split())

        res = 0
        for i in xrange(n):
            l, r = i, n - i - 1
            res += ns[i] * pow(2, l, MOD)
            res -= ns[i] * pow(2, r, MOD)
            res %= MOD

        print (res % MOD + MOD) % MOD
