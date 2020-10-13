
def solve(ns):
    step = 0
    p, q = 0, 0
    n = len(ns)
    m = n
    while p < n and q < n:
        q = max(p, q)
        while q + 1 < n and ns[q] != ns[q + 1]:
            q += 1
        if q + 1 < n:
            step += 1
            cur = ns[p]
            p += 1
            while p < n and ns[p] == cur:
                p += 1
            q += 1
        else:
            cur = ns[p]
            while p < n:
                if ns[p] != cur:
                    break
                p += 1
                
            if p < n:
                cur = ns[p]
                while p < n:
                    if ns[p] != cur:
                        break
                    p += 1
            step += 1
    return step

assert solve('1001') == 2
assert solve('100000111') == 3
assert solve('1') == 1
assert solve('1000001') == 3
assert solve('100') == 2
assert solve('010') == 2
assert solve('10010') == 3
assert solve('111010') == 3
assert solve('101010') == 3

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = raw_input()
    print solve(ns)

