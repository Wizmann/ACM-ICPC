INF = 0x3f3f3f3f

def do_solve(n, k, ns, u):
    cnt = ns.count(u)
    step = 0
    for i in xrange(1, 10):
        a = u + i
        if 0 <= a < 10:
            for j in xrange(n):
                if ns[j] == a and cnt < k:
                    cnt += 1
                    step += i
                    ns[j] = u
        
        b = u - i
        if 0 <= b < 10:
            for j in xrange(n - 1, -1, -1):
                if ns[j] == b and cnt < k:
                    cnt += 1
                    step += i
                    ns[j] = u
    return step, ''.join(map(str, ns))

def solve(n, k, ns):
    mini, res = INF, ''
    for i in xrange(10):
        step, r = do_solve(n, k, ns[:], i)
        if step < mini:
            mini, res = step, r
        elif step == mini and res > r:
            mini, res = step, r
    return mini, res
    
(n, k) = map(int, raw_input().split())
ns = map(int, raw_input())

(mini, res) = solve(n, k, ns)
print mini
print res
