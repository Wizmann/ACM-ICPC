# http://codeforces.com/contest/1313/problem/C1
# http://codeforces.com/contest/1313/problem/C2

def do_solve(ns):
    n = len(ns)
    st = []
    tot = []
    res = []

    for i, num in enumerate(ns):
        while st and ns[st[-1]] >= num:
            st.pop()
            tot.pop()
        pre = 0 if not tot else tot[-1]
        length = i + 1 if not st else i - st[-1]
        tot.append(pre + ns[i] * length)
        st.append(i)
        res.append(tot[-1])
    return res, st

def solve(ns):
    n = len(ns)
    if len(ns) == 1:
        return ns

    a, _ = do_solve(ns)
    b, _ = do_solve(ns[::-1])
    b = b[::-1]

    # print(a, b)

    maxi = -1
    maxp = -1
    for i in range(1, n):
        # print(a[i - 1], b[i])
        u = a[i - 1] + b[i]
        if u > maxi:
            maxi = u
            maxp = i

    _, a = do_solve(ns[:maxp])
    _, b = do_solve(ns[maxp:][::-1])

    # print(a, b)

    res1 = []
    res2 = []

    p = 0
    for i in range(maxp):
        if i <= a[p]:
            res1.append(ns[a[p]])
            if i == a[p]:
                p += 1
    p = 0
    ns = ns[::-1]
    for i in range(n - maxp):
        if i <= b[p]:
            res2.append(ns[b[p]])
            if i == b[p]:
                p += 1
    res = res1 + res2[::-1]
    #print(res)
    return res

assert(solve([1, 2]) == [1, 2])
assert(solve([2, 1]) == [2, 1])
assert(solve([1]) == [1])
assert(solve([1, 6, 4, 5, 1]) == [1, 6, 4, 4, 1])
assert(solve([1, 5, 4, 3, 1]) == [1, 5, 4, 3, 1])
assert(solve([1, 4, 4, 3, 1]) == [1, 4, 4, 3, 1])
assert(solve([1, 2, 4, 3, 1]) == [1, 2, 4, 3, 1])
assert(solve([1, 2, 2, 3, 1]) == [1, 2, 2, 3, 1])
assert(solve([10, 6, 8]) == [10, 6, 6])
assert(solve([1, 2, 1, 2, 1]) == [1, 2, 1, 1, 1])
assert(solve([1, 2, 3, 2, 1]) == [1, 2, 3, 2, 1])

n = int(input())
ns = list(map(int, input().split()))

print(' '.join(map(str, solve(ns))))
