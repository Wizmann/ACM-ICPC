from collections import defaultdict, Counter

MOD = (10 ** 9) + 7

def solve(ns):
    d = defaultdict(int)
    for num in ns:
        if d[num - 1] > 0:
            d[num - 1] -= 1
        d[num] += 1
    return sum(d.values())

if __name__ == '__main__':
    n = int(raw_input())
    ms = map(int, raw_input().split())
    ns = sorted(ms)
    assert len(ns) == n

    rn = solve(ns)

    d = Counter(ms)
    res = 0
    q = int(raw_input())
    for case_ in xrange(1, q + 1):
        (a, b) = map(int, raw_input().split())
        pre = ms[a - 1]
        now = b
        ms[a - 1] = now

        l, r, c = d[pre - 1], d[pre + 1], d[pre]

        if c > l and c > r:
            rn -= 1
        elif c <= l and c <= r:
            rn += 1
        else:
            pass

        d[pre] -= 1

        l, r, c = d[now - 1], d[now + 1], d[now]

        if c >= l and c >= r:
            rn += 1
        elif c >= l or c >= r:
            pass
        else:
            rn -= 1

        d[now] += 1

        res = (res + rn * case_) % MOD

    print res
