import heapq

n = int(raw_input())
ns = [int(raw_input()) for i in xrange(n)]

heapq.heapify(ns)

ans = 0
while len(ns) > 1:
    a = heapq.heappop(ns)
    b = heapq.heappop(ns)
    ans += a + b
    heapq.heappush(ns, a + b)
print ans
