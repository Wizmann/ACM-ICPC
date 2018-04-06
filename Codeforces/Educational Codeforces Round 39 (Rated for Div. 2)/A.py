def solve(ns):
    a = sum(filter(lambda x: x > 0, ns))
    b = sum(filter(lambda x: x < 0, ns))

    return a - b

assert solve([1, -2, 0]) == 3
assert solve([16, 23, 16, 15, 42, 8]) == 120

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print solve(ns)
