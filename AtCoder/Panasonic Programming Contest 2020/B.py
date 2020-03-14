# https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b

(n, m) = map(int, raw_input().split())

res = 0

if n == 1 or m == 1:
    print 1
else:
    res += ((n + 1) / 2) * ((m + 1) / 2)
    res += (n / 2) * (m / 2)
    print res
