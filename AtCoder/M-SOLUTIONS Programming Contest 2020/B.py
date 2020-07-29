R = 0
G = 1
B = 2


def check(ns):
    return ns[G] > ns[R] and ns[B] > ns[G]

def solve(ns, k):
    if check(ns):
        return True
    if k == 0:
        return False
    for i in xrange(3):
        ms = ns[:]
        ms[i] *= 2
        if solve(ms, k - 1):
            return True
    return False


assert solve([7, 2, 5], 3) == True
assert solve([7, 4, 2], 3) == False


ns = map(int, raw_input().split())
k = int(raw_input())

print 'Yes' if solve(ns, k) else 'No'

