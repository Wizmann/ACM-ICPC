def median(ns):
    n = len(ns)
    if n % 2 == 0:
        return (ns[n / 2 - 1] + ns[n / 2]) / 2
    else:
        return ns[n / 2]
    
n = int(raw_input())
ns = sorted(map(int, raw_input().split()))

m = median(ns)

l, r = filter(lambda x: x < m, ns), filter(lambda x: x > m, ns)

print median(l)
print m
print median(r)
