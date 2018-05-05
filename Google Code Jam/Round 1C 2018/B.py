import sys
import random
from collections import defaultdict

T = int(raw_input())

for case_ in xrange(T):
    d = defaultdict(int)
    n = int(raw_input())

    ll = set([i for i in xrange(0, n)])

    for i in xrange(n):
        pref = map(int, raw_input().split())[1:]

        for p in pref:
            d[p] += 1
        pref.sort(key = lambda p: d[p])

        for p in pref:
            if p not in ll:
                continue
            else:
                ll.remove(p)
                print p
                break
        else:
            print -1
        sys.stdout.flush()
        




