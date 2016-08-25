def solve(n, ns):
    ns.sort()
    idx = (n + 1) / 2 - 1
    return ns[idx]

assert solve(4, [1, 2, 3, 4]) == 2
assert solve(3, [1, 2, 3]) == 2
assert solve(1, [0]) == 0
assert solve(2, [0, 10000]) == 0

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print solve(n, ns)
