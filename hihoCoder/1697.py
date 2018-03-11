def solve(ns):
    if not ns:
        return []

    mini = min(ns)
    idx = ns.index(mini)

    return [mini] + solve(ns[:idx]) + solve(ns[idx + 1:])

assert solve([5, 4, 1, 3, 2]) == [1, 4, 5, 2, 3]

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, [raw_input() for i in xrange(n)])

    print '\n'.join(map(str, solve(ns)))
