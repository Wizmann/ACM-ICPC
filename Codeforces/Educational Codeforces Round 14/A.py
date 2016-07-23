n = int(raw_input())
ns = map(int, raw_input().split())

print 'YES' if sum(ns) == (n if n == 1 else n - 1) else 'NO'
