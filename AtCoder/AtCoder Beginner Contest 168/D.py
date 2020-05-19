from collections import defaultdict, deque

(n, m) = map(int, raw_input().split())

d = defaultdict(list)

for i in xrange(m):
    (a, b) = map(int, raw_input().split())
    d[a].append(b)
    d[b].append(a)

pre = [0 for i in xrange(n + 1)]
cnt = 0

q = deque([1])
while q:
    cur = q.popleft()
    for nxt in d[cur]:
        if pre[nxt] == 0:
            cnt += 1
            pre[nxt] = cur
            q.append(nxt)


if cnt < n - 1:
    print 'No'
else:
    print 'Yes'
    for i in xrange(2, n + 1):
        print pre[i]
