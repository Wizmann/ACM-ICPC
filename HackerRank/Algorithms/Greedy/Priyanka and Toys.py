INF = 0x3f3f3f3f

n = int(raw_input())
ns = sorted(map(int, raw_input().split()))

ans = 0
flag = -INF
for num in ns:
    if num > flag:
        flag = num + 4
        ans += 1
print ans
