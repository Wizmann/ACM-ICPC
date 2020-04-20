import sys
if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    
    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()

INF = 10 ** 10

def do_solve(ptr, monsters):
    n = len(monsters)
    tot, pre = monsters[ptr]
    for i in xrange(1, n):
        p = (ptr + i) % n
        u = max(0, monsters[p][0] - pre)
        tot += u
        pre = monsters[p][1]
    return tot

def brute_force(monsters):
    assert False
    n = len(monsters)
    mini = INF
    minp = -1
    ps = []
    for i in xrange(n):
        res = do_solve(i, deepcopy(monsters))
        if res < mini:
            mini = res
            ps = [i]
        elif res == mini:
            ps.append(i)

    ds = []
    for i in xrange(n):
        nxt = (i + 1 + n) % n
        (a, b) = monsters[i]
        (na, nb) = monsters[nxt]
        ds.append((a, min(b, na)))

    return mini

def solve(monsters):
    n = len(monsters)

    tot = do_solve(0, monsters)
    res = tot

    for i in xrange(1, n):
        idx_p2 = (i + n - 2) % n
        idx_p1 = (i + n - 1) % n
        idx = i
        idx_n1 = (i + n + 1) % n

        tot -= min(monsters[idx_p1][0], monsters[idx_p2][1])
        tot -= max(0, monsters[idx][0] - monsters[idx_p1][1])
        tot += monsters[idx][0]

        res = min(res, tot)
    return res

assert solve([[7, 15], [2, 14], [5, 3]]) == 6
assert solve([[9, 10], [8, 2], [7, 1]]) == 14
assert solve([[8, 9], [4, 4], [2, 5], [9, 7], [9, 3], [5, 4], [4, 9]]) == 10
assert solve([[8, 10], [9, 5], [5, 9], [2, 4], [8, 1], [9, 6], [8, 3]]) == 20

'''
def test():
    from random import randint
    for i in xrange(500):
        n = randint(1, 10)
        monsters = [[randint(1, 10), randint(1, 10)] for i in xrange(n)]
        m1 = deepcopy(monsters)
        m2 = deepcopy(monsters)

        print monsters
        print brute_force(m1)
        assert brute_force(m1) == solve(m2)

test()
import sys
sys.exit(0)
'''

import sys
T = int(raw_input())

ans = []
for case_ in xrange(T):
    n = int(raw_input())
    monsters = []
    for i in xrange(n):
        (a, b) = map(int, sys.stdin.readline().split())
        monsters.append([a, b])

    ans.append(solve(monsters))

sys.stdout.write('\n'.join(map(str, ans)))
