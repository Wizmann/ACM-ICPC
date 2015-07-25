import sys
sys.stdin = open('input.txt')

class Point(object):
    def __init__(self, pos, weight):
         self.pos = pos
         self.weight = weight
    
    def __repr__(self):
        return '(%d, %d)' % (self.pos, self.weight)
         
n = int(raw_input())
ns = [Point(*map(int, raw_input().split())) for i in xrange(n)]

ns.sort(key=lambda x: x.pos)

left = [0 for i in xrange(n)]
right = [0 for i in xrange(n)]

cnt = 0
weight = 0
for i in xrange(n):
    if i:
        left[i] += left[i - 1]
        delta = ns[i].pos - ns[i - 1].pos
    else:
        delta = 0
    left[i] += weight * delta
    weight += ns[i].weight

weight = 0
for i in xrange(n - 1, -1, -1):
    if i != n - 1:
        right[i] += right[i + 1]
        delta = ns[i + 1].pos - ns[i].pos
    else:
        delta = 0
    right[i] += weight * delta
    weight += ns[i].weight
ans = 0xdeadbeefdeadbeef
for i in xrange(n):
    ans = min(ans, left[i] + right[i])
print ans
