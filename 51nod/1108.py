def get_dis(n, ns):
    pivot = ns[n / 2]
    return sum(map(lambda x: abs(x - pivot), ns))

n = int(raw_input())

xs, ys, zs = [], [], []
for i in xrange(n):
    x, y, z = map(int, raw_input().split())
    xs.append(x)
    ys.append(y)
    zs.append(z)

xs.sort()
ys.sort()
zs.sort()

ans = 0
ans += get_dis(n, xs)
ans += get_dis(n, ys)
ans += get_dis(n, zs)

print ans
