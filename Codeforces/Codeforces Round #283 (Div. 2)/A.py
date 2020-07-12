from collections import defaultdict

INF = 10 ** 20

def solve(ns):
    n = len(ns)
    maxi = 0
    for i in xrange(n - 1):
        delta = ns[i + 1] - ns[i]
        maxi = max(maxi, delta)

    mini = INF
    for i in xrange(1, n - 1):
        delta = ns[i + 1] - ns[i - 1]
        mini = min(mini, max(maxi, delta))
    return mini

assert solve([1, 4, 6]) == 5
assert solve([1, 2, 3, 4, 5]) == 2
assert solve([1, 2, 3, 7, 8]) == 4

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print solve(ns)
