from fractions import gcd

def lcm(a, b):
    return a * b / gcd(a, b)

(t, w, b) = map(int, raw_input().split())

l = lcm(w, b)
c = (t / l) + 1
m = t % l

x = c * min(w, b) - 1

if m < min(w, b):
    x = x - min(w, b) + m + 1

y = t
g = gcd(x, y)

print '%d/%d' % (x /g, y / g)
