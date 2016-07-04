#coding=utf-8

def solve(n, a, ns):
    ans = set()
    a -= 1
    for i in xrange(n):
        l, r = a - i, a + i
        s, avail = 0,  []
        if 0 <= l < n:
            avail.append(l)
            s += ns[l]
        if 0 <= r < n:
            avail.append(r)
            s += ns[r]

        if s == len(avail) and s:
            ans |= set(avail)
    return len(ans)

assert solve(6, 3, [1,1,1,0,1,0]) == 3
assert solve(5, 2, [0,0,0,1,0]) == 1

if __name__ == '__main__':
    (n, a) = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    print solve(n, a, ns)
