n = int(raw_input())
pokers = map(int, raw_input().split())

v = [0, 0]
p = 0

for i in xrange(n):
    if pokers[0] > pokers[-1]:
        v[p] += pokers[0]
        del pokers[0]
    else:
        v[p] += pokers[-1]
        del pokers[-1]
    p ^= 1

print v[0], v[1]
