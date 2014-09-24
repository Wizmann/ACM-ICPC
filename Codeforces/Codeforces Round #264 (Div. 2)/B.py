n = int(raw_input())
hs = [0] + map(int, raw_input().split())

ans = 0
ene = 0
for i in xrange(n):
    now = hs[i]
    nex = hs[i + 1]
    delta = now - nex
    if delta > 0:
        ene += delta
    else:
        delta = abs(delta)
        if (ene < delta):
            ans += delta - ene
            ene = 0
        else:
            ene -= delta

print ans
