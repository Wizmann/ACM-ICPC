def solve(ns, pre=-1):
    res = []
    l, r = 0, len(ns) - 1
    while l <= r:
        if min(ns[l], ns[r]) > pre:
            if ns[l] < ns[r]:
                pre = ns[l]
                res.append('L')
                l += 1
            elif ns[l] > ns[r]:
                pre = ns[r]
                res.append('R')
                r -= 1
            else:
                t1 = ['L'] + solve(ns[l + 1: r + 1], ns[l])
                t2 = ['R'] + solve(ns[l: r], ns[r])
                if len(t1) > len(t2):
                    res += t1
                    break
                else:
                    res += t2
                    break
        elif ns[l] > pre:
            pre = ns[l]
            res.append('L')
            l += 1
        elif ns[r] > pre:
            pre = ns[r]
            res.append('R')
            r -= 1
        else:
            break
    return res


n = int(raw_input())
ns = map(int, raw_input().split())

res = solve(ns)
print len(res)
print ''.join(res)
