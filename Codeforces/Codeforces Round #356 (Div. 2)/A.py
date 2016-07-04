ns = map(int, raw_input().split())

d = {}

for num in ns:
    d[num] = d.get(num, 0) + 1

s = sum(ns)
ans = s

for key, value in d.items():
    if value >= 2:
        ans = min(ans, s - 2 * key)
    if value >= 3:
        ans = min(ans, s - 3 * key)

print ans
