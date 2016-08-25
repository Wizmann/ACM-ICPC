import sys

sys.stdin = open('input.txt')

T = int(raw_input())

def cross_product(p, q):
    i = p[1] * q[2] - p[2] * q[1]
    j = p[2] * q[0] - p[0] * q[2]
    k = p[0] * q[1] - p[1] * q[0]
    return (i, j, k)
    
def dot_product(p, q):
    i = p[0] * q[0]
    j = p[1] * q[1]
    k = p[2] * q[2]
    return (i, j, k)

def vector_minus(p, q):
    i = p[0] - q[0]
    j = p[1] - q[1]
    k = p[2] - q[2]
    return (i, j, k)

def solve():
    a, b, c, d = [tuple(map(int, raw_input().split())) for i in xrange(4)]
    x = vector_minus(a, b)
    y = vector_minus(c, d)
    z = vector_minus(a, d)
    
    p = cross_product(x, y)
    q = dot_product(p, z)
    print 'Yes' if sum(q) == 0 else 'No'
    
for case_ in xrange(T):
    solve()
