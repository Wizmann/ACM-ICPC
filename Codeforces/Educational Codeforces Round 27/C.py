def solve(ns):
    ns = sorted(ns, key=lambda x: x[0])
    tv = [-1, -1]
    for (l, r) in ns:
        if l > min(tv):
            tv = [r, max(tv)]
        elif l <= min(tv):
            return False
    return True

assert solve([
    (1, 2),
    (2, 3),
    (4, 5)
]) == True

assert solve([
    (1, 2),
    (2, 3),
    (2, 3),
    (1, 2)
]) == False

if __name__ == '__main__':
    n = int(raw_input())
    ns = []
    for i in xrange(n):
        (a, b) = map(int, raw_input().split())
        ns.append((a, b))

    if solve(ns):
        print 'YES'
    else:
        print 'NO'
