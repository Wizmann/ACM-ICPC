import sys

def topsort(n, g, indegree):
    cnt = n
    visit = set()
    while cnt:
        for key, value in indegree.items():
            if key in visit:
                continue
            if value == 0:
                cur = key
                break
        else:
            return False
        visit.add(cur)
        for next in g.get(cur, []):
            indegree[next] -= 1
            if indegree[next] < 0:
                return False
        cnt -= 1
    return True

def solve():
    n = int(raw_input())
    idx = 0
    d = {}
    g = {}
    indegree = {}
    
    for i in xrange(n):
        places = sys.stdin.readline().strip().split(',')
        for i, place in enumerate(places):
            if place not in d:
                d[place] = idx
                idx += 1
            
            pid = d[place]
            if i - 1 >= 0:
                indegree[pid] = indegree.get(pid, 0) + 1
                ppid = d[places[i - 1]]
                g[ppid] = g.get(ppid, []) + [pid]
    n = len(d)
    for i in xrange(n):
        if i not in indegree:
            indegree[i] = 0
    if topsort(n, g, indegree):
        print 'ORDER EXISTS'
    else:
        print 'ORDER VIOLATION'           
            

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        solve()
