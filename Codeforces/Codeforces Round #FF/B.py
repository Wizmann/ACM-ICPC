s = raw_input()
k = int(raw_input())
values = map(int, raw_input().split())
ans = 0

for i, c in enumerate(s):
    ans += (i + 1) * values[ord(c) - ord('a')]

m = max(values)
for i in xrange(len(s), len(s) + k):
    ans += (i + 1) * m
print ans
