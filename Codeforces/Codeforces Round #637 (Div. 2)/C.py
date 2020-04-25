import sys
if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    
    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()

def solve(ns):
    n = len(ns)
    d = {}
    for i, num in enumerate(ns):
        d[num] = i

    ub = n
    for i in xrange(1, n + 1):
        p = d[i]
        if ns[p] == -1:
            continue
        for j in xrange(p, ub):
            expected = i + (j - p)
            if ns[j] != expected:
                return False
            ns[j] = -1
        # print ns
        ub = p
    return True

assert solve([2, 3, 1, 4]) == False
assert solve([4, 3, 1, 2]) == True
assert solve([4, 2, 3, 1]) == True
assert solve([2, 3, 4, 5, 1]) == True


T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print 'Yes' if solve(ns) else 'No'
