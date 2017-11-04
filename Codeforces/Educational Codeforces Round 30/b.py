n = int(raw_input())
ns = map(int, raw_input())

d = {0: -1}
ans = 0
s = 0
for i, num in enumerate(ns):
    s += 1 if num == 1 else -1
    if s in d:
        ans = max(ans, i - d[s])
    else:
        d[s] = i

print ans
