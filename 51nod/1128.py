def count_group(ns, m, k):
    cnt = 0
    s = 0
    for num in ns:
        if num > m:
            return False
        s += num
        if s > m:
            cnt += 1
            s = num
    if s:
        cnt += 1
    return cnt <= k

(n, k) = map(int, raw_input().split())
ns = [int(raw_input()) for i in xrange(n)]

l = 0
r = 10 ** 10

while l <= r:
    m = (l + r) >> 1
    flag = count_group(ns, m, k)
    
    if flag:
        r = m - 1
    else:
        l = m + 1

print l
