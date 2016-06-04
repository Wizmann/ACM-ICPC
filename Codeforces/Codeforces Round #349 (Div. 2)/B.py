n = int(raw_input())
ns = map(int, raw_input().split())

mm = max(ns)
s = sum(ns)

print mm - (s - mm) + 1