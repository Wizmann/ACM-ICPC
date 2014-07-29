n = int(raw_input())
xs = map(int, raw_input().split())
ys = sorted(xs)

l, r = 0, n - 1

while l < n and xs[l] == ys[l]:
    l += 1

while r >= 0 and xs[r] == ys[r]:
    r -= 1

if l == n or r == -1:
    l = r = 0
ans = (l + 1, r + 1)

while l < r:
    if xs[l] < xs[l + 1]:
        print 'no'
        break
    l += 1
else:
    print 'yes'
    print ' '.join(map(str, ans))
