# https://codeforces.com/contest/1312/problem/A

T = int(raw_input())
for case_ in xrange(T):
    (n, m) = map(int, raw_input().split())
    print 'YES' if n % m == 0 else 'NO'
