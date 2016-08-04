import sys
import heapq

(n, k) = map(int, input().split())
ns = list(map(int, input().split()))
cnt = 0

heapq.heapify(ns)

while len(ns) >= 2:
    a = heapq.heappop(ns)
    if a >= k:
        print(cnt)
        sys.exit(0)

    b = heapq.heappop(ns)
    c = a + 2 * b
    cnt += 1
    heapq.heappush(ns, c)
if min(ns) >= k:
    print(cnt)
else:
    print(-1)
    
    
    
    
