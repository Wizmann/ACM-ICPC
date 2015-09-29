n = int(raw_input())
ns = map(int, raw_input().split()) + [-1]

ans = 0
pre = -1
l = 0

for i, num in enumerate(ns):
    if num >= pre:
        l += 1
    else:
        l = 1

    ans = max(ans, l)
    pre = num

print ans
