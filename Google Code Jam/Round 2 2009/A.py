if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = []
        for i in xrange(n):
            s = raw_input()
            if '1' not in s:
                ns.append(0)
            else:
                ns.append(s.rindex('1') + 1)
        ans = 0
        for i in xrange(n):
            for j in xrange(i, n):
                if ns[j] <= i + 1:
                    ns = [ns[j]] + ns[:j] + ns[j + 1:]
                    ans += j - i
                    break
        print 'Case #%d: %d' % (case_ + 1, ans)
