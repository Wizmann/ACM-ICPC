a, b, c, d = map(int, input().split())

eps = 1e-12

p = 0
pre = 1.
while True:
    delta = 1.0 * pre * a / b 
    if delta < eps:
        break
    pre = pre * (b - a) / b * (d - c) / d
    p += delta
print(p)

