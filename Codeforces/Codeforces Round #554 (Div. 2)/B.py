def isLongcat(n):
    return (n & (n + 1)) == 0

def opA(n):
    v = -1
    for i in xrange(32, -1, -1):
        if (1 << i) > n:
            continue
        if (n & (1 << i)) == 0:
            v = i + 1
            break
    assert v != -1
    return v

assert opA(2) == 1

def solve(n):
    cnt = 0
    step = []
    while True:
        if isLongcat(n):
            return cnt, step
        v = opA(n)
        cnt += 1
        step.append(v)
        n ^= (1 << v) - 1
        if isLongcat(n):
            return cnt, step
        n += 1
        cnt += 1
        if isLongcat(n):
            return cnt, step


if __name__ == '__main__':
    n = int(raw_input())
    cnt, step = solve(n)
    if cnt == 0:
        print 0
    else:
        print cnt
        print ' '.join(map(str, step))
