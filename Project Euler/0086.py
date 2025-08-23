import math

def is_square(n:int)->bool:
    r = int(math.isqrt(n))
    return r*r == n

LIMIT = 3000

max_s = 2*LIMIT
# Build boolean table leg_ok[a][s]
leg_ok = [[False]*(max_s+1) for _ in range(LIMIT+1)]
for a in range(1, LIMIT+1):
    aa = a*a
    for s in range(2, max_s+1):  # s=b+c, minimal 2 when b=c=1 (but we'll use b>=c so s>=2)
        if is_square(aa + s*s):
            leg_ok[a][s] = True

# Build prefix sums over s for each a to range-count quickly
pref = [[0]*(max_s+1) for _ in range(LIMIT+1)]
for a in range(1, LIMIT+1):
    run = 0
    for s in range(0, max_s+1):
        run += 1 if leg_ok[a][s] else 0
        pref[a][s] = run

def calc_fast(LIMIT:int)->int:
    total = 0
    # Enumerate a >= b >= c via (a,b), then count c by s in (b, 2b]
    for a in range(1, LIMIT+1):
        for b in range(1, a+1):
            hi = 2*b
            lo = b  # we want (b, 2b], so subtract pref at b
            if hi > max_s:
                hi = max_s
            cnt = pref[a][hi] - pref[a][lo]
            total += cnt
    return total


assert calc_fast(99) == 1975
assert calc_fast(100) == 2060

GOAL = 10 ** 6
l, r = 0, LIMIT
while l <= r:
    m = (l + r) // 2
    u = calc_fast(m)
    if u > GOAL:
        r = m - 1
    else:
        l = m + 1
print(l)
