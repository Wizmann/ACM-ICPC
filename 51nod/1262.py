n = int(raw_input())

n += 1

ans = n
cur = 2
while n > 1:
    cnt = 0
    while n % cur == 0:
        n /= cur
        cnt += 1
    if cnt:
        ans = ans / cur * (cur - 1)
    cur += 1
print ans
