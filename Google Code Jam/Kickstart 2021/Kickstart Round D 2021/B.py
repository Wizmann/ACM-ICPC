from collections import defaultdict

INF = 10 ** 10

T = int(raw_input())

for case_ in xrange(T):
    n, c = map(int, raw_input().split())
    events = set()
    eplus = defaultdict(int)
    eminus = defaultdict(int)
    for i in xrange(n):
        a, b = map(int, raw_input().split())
        events.add(a)
        events.add(b)
        events.add(b - 1)
        eplus[a] += 1
        eminus[b] += 1

    segs = []
    pre = 0
    cnt = 0
    for pos in sorted(events):
        cnt -= eminus[pos]
        length = pos - pre
        if cnt:
            segs.append((cnt, length))
        # print pos, cnt, length
        cnt += eplus[pos]

        pre = pos

    segs.sort(reverse=True)
    tot = 0
    for (cnt, length) in segs:
        if not c:
            break
        current = min(c, length)
        tot += current * cnt
        c -= current

    print 'Case #%d: %d' % (case_ + 1, tot + n)


'''
^^^TEST^^^
1
3 3
1 3
2 4
1 4
--------
Case #1: 7
$$$TEST$$$

^^^TEST^^^
1
2 10000
1 2
2 3
--------
Case #1: 2
$$$TEST$$$

^^^TEST^^^
1
2 10000
1 3
1 3
--------
Case #1: 4
$$$TEST$$$
'''



