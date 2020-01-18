n, k, m = map(int, raw_input().split())
ns = map(int, raw_input().split())
 
tot = sum(ns)
exp = m * n
 
need = max(0, exp - tot)
 
if need > k:
    print -1
else:
    print need
