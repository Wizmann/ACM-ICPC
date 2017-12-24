def solve(ns):
    ns.sort()
    n = len(ns)
    p, q = 0, 0

    while p < n and q < n:
        if p < q and ns[p] < ns[q]:
            p += 1
        q += 1
    return q - p

assert solve([1, 1, 2, 3]) == 2
assert solve([1, 2, 3]) == 1
assert solve([1, 2, 3, 3]) == 2
assert solve([4, 2, 4, 3]) == 2

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print solve(ns)
