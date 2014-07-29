def do_solve(n, k, d1, d2):
    w1 = 2 * d1 + k + d2
    if w1 % 3:
        return False
    w1 /= 3
    w2 = w1 - d1
    w3 = w2 - d2
    ws = [w1, w2, w3]
    #print ws

    if all(map(lambda x: x >= 0, ws)) \
            and all(map(lambda x: x <= n / 3, ws)):
        return True
    else:
        return False

def solve(n, k, d1, d2):
    if n % 3:
        return False
    return do_solve(n, k, d1, d2) \
            or do_solve(n, k, -d1, d2) \
            or do_solve(n, k, d1, -d2) \
            or do_solve(n, k, -d1, -d2)


T = int(raw_input())

for i in xrange(T):
    (n, k, d1, d2) = map(int, raw_input().split())
    if solve(n, k, d1, d2):
        print 'yes'
    else:
        print 'no'

