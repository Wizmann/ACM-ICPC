def solve():
    ans = []
    (n, k, p) = map(int, raw_input().split())
    nums = map(int, raw_input().split())

    evens = filter(lambda x: x % 2 == 0, nums)
    odds  = filter(lambda x: x % 2 == 1, nums)

    n_even, n_odd = p, k - p

    if len(odds) < n_odd or \
            (len(odds) - n_odd) % 2 == 1 or \
            len(evens) + (len(odds) - n_odd) / 2 < p:
        return []
    
    for i in xrange(p):
        if not evens:
            break
        ans.append([evens.pop()])
        n_even -= 1
    for i in xrange(k - p):
        if not odds:
            break
        ans.append([odds.pop()])
        n_odd -= 1

    # assert(not n_odd)

    if not n_even:
        ans[-1] += odds + evens
    else:
        for i in xrange(n_even):
            if i == n_even - 1:
                ans.append(odds)
            else:
                ans.append([odds.pop(), odds.pop()])

    return ans

if __name__ == '__main__':
    ans = solve()
    if not ans:
        print 'NO'
    else:
        print 'YES'
        for line in ans:
            print len(line),
            for item in line:
                print item,
            print ''


