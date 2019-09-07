MOD = 1000000007

n = int(raw_input())
ns = map(int, raw_input().split())

p = ns.pop()
while ns:
    q = ns.pop()
    p = p + q + p * q
    p %= MOD
print p
