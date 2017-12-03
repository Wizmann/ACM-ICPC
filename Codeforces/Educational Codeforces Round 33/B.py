ns = []

for i in xrange(1000):
    u = ((2 ** i) - 1) * (2 ** (i - 1))
    if u <= 10 ** 5:
        ns.append(u)
    else:
        break

n = int(raw_input())
for num in ns[::-1]:
    if n % num == 0:
        print num
        break
