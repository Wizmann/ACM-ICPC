(n, m) = map(int, raw_input().split())

k = 0
x, y = -1, -1
ans = 0xdeadbeef
while k * m <= n:
    y = n - k * m
    x = n - 2 * y
    if x >= 0 and y >= 0:
        ans = min(ans, x + y)
    k += 1

if ans == 0xdeadbeef:
    ans = -1
print ans
