(n, x) = map(int, raw_input().split())
ts = map(int, raw_input().split())

ans = 0
ts.sort()
for item in ts:
    ans += x * item
    x = max(1, x - 1)

print ans
