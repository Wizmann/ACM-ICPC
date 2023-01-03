
T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    for i in xrange(2, 23456789):
        # print '---'
        l, r0, r1 = 1, n - 1, i + 1
        # print i, l, r0, r1
        u = (r1 - l) ** 2
        v = (l + r0) * (n - 1) / 2 + r1
        if v > u:
            continue
        delta = u - v
        # print u, v, delta
        base = delta / n

        rem = delta % n

        if rem >= n - 2:
            if r0 + base + 2 >= r1 + base:
                continue
        else:
            if r0 + base + 1 >= r1 + base:
                continue

        ans = range(l + base, r0 + base + 1) + [r1 + base]

        idx = n - 2
        # print idx
        # print n, rem, ans[-2], ans[-1]
        while rem:
            ans[idx] += 1
            rem -= 1
            idx -= 1
            if idx == 0:
                idx = n - 2
        if ans[-2] >= ans[-1]:
            print ans[-2], ans[-1]
            assert False
            continue
        print ' '.join(map(str, ans))
        assert(sum(ans) == (max(ans) - min(ans)) ** 2)
        break

'''

^^^^TEST^^^
1
3
------
<ignore>
$$$$TEST$$$

^^^^TEST^^^
3
2
5
4
------
<ignore>
$$$$TEST$$$
'''
