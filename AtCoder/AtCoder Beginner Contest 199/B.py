INF = 10 ** 10

n = int(raw_input())
A = map(int, raw_input().split())
B = map(int, raw_input().split())

l = -INF
r = INF

for (a, b) in zip(A, B):
    l = max(l, a)
    r = min(r, b)


print max(0, r - l + 1)
