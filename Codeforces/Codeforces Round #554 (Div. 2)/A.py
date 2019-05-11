(n, m) = map(int, raw_input().split())
ns = map(lambda x: x % 2, map(int, raw_input().split()))
ms = map(lambda x: x % 2, map(int, raw_input().split()))

nodd, neven = sum(ns), n - sum(ns)
modd, meven = sum(ms), m - sum(ms)

print min(nodd, meven) + min(neven, modd)
