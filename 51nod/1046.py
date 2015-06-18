(a, b, c) = map(int, raw_input().split())

aa = a
res = 1
while b:
    if b & 1:
        res = (res * aa) % c
    aa = (aa * aa) % c
    b >>= 1
print res % c
