import sys
import heapq


s = raw_input()

costs = []
for line in sys.stdin:
    costs.append(tuple(map(int, line.split())))
    

ans = sum(map(lambda x: x[0], costs))

pq = []
rank = 0
idx = 0
ans = 0
for i, c in enumerate(s):
    rank += {
        '(': 1,
        ')': -1,
        '?': 0
    }[c]
    if c == '?':
        x, y = costs[idx]
        heapq.heappush(pq, x - y)
        ans += y
        idx += 1
        rank -= 1
    if rank < 0:
        if not pq:
            rank = -1
            break
        cur = heapq.heappop(pq)
        ans += cur
        rank += 2
if rank == 0:
    print ans
else:
    print -1
