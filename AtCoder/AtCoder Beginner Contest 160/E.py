(x, y, A, B, C) = map(int, raw_input().split())

ps = sorted(map(int, raw_input().split()), reverse=True)[:x]
qs = sorted(map(int, raw_input().split()), reverse=True)[:y]
cs = sorted(map(int, raw_input().split()))

res = sorted(ps + qs, reverse=True)
tot = sum(res)

while cs and res and cs[-1] >= res[-1]:
    tot -= res.pop()
    tot += cs.pop()

print tot


