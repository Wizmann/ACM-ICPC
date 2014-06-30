n = int(raw_input())
ps = map(float, raw_input().split())

ps.sort(reverse=True)

good = ps[0]
bad = 1 - good

ans = good

for p in ps[1:]:
    good, bad = good * (1 - p) + p * bad, bad * (1 - p)
    ans = max(ans, good)

print ans
