import sys
if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    
    sys.stdin = io.BytesIO(sys.stdin.read())
    input = lambda: sys.stdin.readline().rstrip()
 
st = set()
 
N = 2
 
first = []
 
ptr = 1
for i in xrange(N):
    while ptr in st:
        ptr += 1
    a = ptr
    ptr += 1
    qtr = ptr
    while True:
        while qtr in st:
            qtr += 1
        if (qtr ^ a) not in st:
            b = qtr
            break
        else:
            qtr += 1
    c = a ^ b
    assert c not in st
    st |= set([a, b, c])
    first += [a, b, c]
    '''
    print "{:10b}".format(a)
    print "{:10b}".format(b)
    print "{:10b}".format(c)
    print '--'
    '''
 
def solve(n):
    m = (n + 2) / 3
    if m == 1:
        return (1, 2, 3)[(n - 1) % 3]
 
    group = m - 1
 
    u = 1
    while m > u:
        m -= u
        u = u * 4
 
    # print u, m
 
    m -= 1
    a = u + m
 
    perm = [ ('00', '00', '00'), ('01', '10', '11'), ('10', '11', '01'), ('11', '01', '10')]
 
    bits = (len('{:b}'.format(a)) - 1) / 2
 
    b = ''
    c = ''
    for i in xrange(bits):
        p = perm[m % 4]
        b = p[1] + b
        c = p[2] + c
        m /= 4
    b = int('10' + b, 2)
    c = int('11' + c, 2)
    return (a, b, c)[(n - 1) % 3]
 
assert solve(8) == 10
assert solve(7) == 5
assert solve(4) == 4
assert solve(3) == 3
assert solve(1) == 1
 
for i, u in enumerate(first):
    v = solve(i + 1)
    assert u == v
 
 
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print solve(n)
