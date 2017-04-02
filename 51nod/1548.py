def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

(C, hr, hb, wr, wb) = map(int, raw_input().split())

ans, i, r = 0, 0, C
while i * i <= r and i * wr <= r:
    vr = i * hr
    vb = (r - i * wr) / wb * hb
    ans = max(ans, vr + vb)
    i += 1

i = 0
while i * i <= r and i * wb <= r:
    vb = i * hb
    vr = (r - i * wb) / wr * hr
    ans = max(ans, vr + vb)
    i += 1
    
print ans
