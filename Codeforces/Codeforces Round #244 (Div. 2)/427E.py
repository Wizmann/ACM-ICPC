n, m = map(int, raw_input().split())
ps = map(int, raw_input().split())

l, r = 0, n - 1

ans = 0
while l < r:
    dis = ps[r] - ps[l]
    l += m
    r -= m
    ans += dis * 2

print ans


