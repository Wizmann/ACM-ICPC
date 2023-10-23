#coding=utf-8
import sys
from collections import defaultdict

d = defaultdict(list)

for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    assert len(line) == 3
    for i in xrange(3):
        for j in xrange(i + 1, 3):
            d[int(line[i])].append(int(line[j]))

for key, nxts in d.items():
    print key, set(nxts)
    for nxt in set(nxts):
        assert key not in d[nxt]

# Then we can get the answer "73162890" manully
