import heapq

def solve(n, k1, k2, As, Bs):
    ns = [-abs(As[i] - Bs[i]) for i in xrange(n)]
    heapq.heapify(ns)
    for i in xrange(k1 + k2):
        if not ns:
            break;
        u = -heapq.heappop(ns)
        u = abs(u - 1)
        heapq.heappush(ns, -u)
    return sum([num * num for num in ns])

assert solve(2, 0, 0, [1, 2], [2, 3]) == 2
assert solve(2, 1, 0, [1, 2], [2, 2]) == 0
assert solve(2, 5, 7, [3, 4], [14, 4]) == 1

if __name__ == '__main__':
    (n, k1, k2) = map(int, raw_input().split())
    As = map(int, raw_input().split())
    Bs = map(int, raw_input().split())
    print solve(n, k1, k2, As, Bs)
