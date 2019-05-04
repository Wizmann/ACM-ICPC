import sys
from collections import defaultdict

T, F = map(int, raw_input().split())

for case_ in xrange(T):
    teams = range(119)
    res = ''
    cnt = 0
    tot = 120
    for i in xrange(5):
        tot /= (5 - i)
        d = defaultdict(list)
        for team in teams:
            idx = 5 * team + i
            assert team < 199
            assert idx + 1 <= 595
            print idx + 1
            cnt += 1
            assert cnt <= F
            sys.stdout.flush()

            member = raw_input()
            d[member].append(team)
        '''
        print tot
        for member in 'ABCDE':
            if member in res:
                continue
            print member, len(d[member])
        '''
        for member in 'ABCDE':
            if member in res:
                continue
            if len(d[member]) != tot:
                res += member
                teams = d[member]
                break
    print res
    sys.stdout.flush()
    judge = raw_input()
    if judge == 'N':
        break
