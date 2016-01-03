import sys
import Queue

INF = 0x3f3f3f3f

def solve(line):
    d = {}
    left, right = line.split('|')
    src, dest = map(int, right.split())
    for tp in left.split(','):
        (a, b, c) = map(int, tp.split())
        d[a] = d.get(a, [])
        d[b] = d.get(b, [])

        d[a].append((b, c))
        d[b].append((a, c))

    dis = {}
    for key in d.keys():
        dis[key] = INF
    dis[src] = dis[dest] = INF

    q = Queue.Queue()
    s = set()

    q.put_nowait(src)
    s.add(src)
    dis[src] = 0

    while not q.empty():
        cur = q.get_nowait()
        s.remove(cur)
        for (next, cost) in d.get(cur, []):
            if dis[next] > dis[cur] + cost:
                dis[next] = dis[cur] + cost
                if next not in s:
                    q.put_nowait(next)
                    s.add(next)

    if dis[dest] >= INF:
        return 'False'
    return dis[dest]

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    print solve(test)
test_cases.close()
