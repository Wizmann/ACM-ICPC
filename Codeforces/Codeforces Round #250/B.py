import sys

sys.stdin = open("b.txt")

def lowbit(x):
    return x & (-x)

(ss, limit) = map(int, raw_input().split())
dd = {}

for i in xrange(1, limit + 1):
    v = lowbit(i)
    dd[v] = dd.get(v, [])
    dd[v].append(i)

g = 0
ans = []
for i in xrange(32, -1, -1):
    v = 1 << i
    t = ss & v
    if t:
        g += 1
    
    nums = dd.get(v, [])
    if len(nums) <= g:
        ans += nums
        g -= len(nums)
    else:
        for i in xrange(g):
            ans.append(nums[i])
        g = 0
    
    g *= 2

if g:
    print -1
else:
    print len(ans)
    print ' '.join(map(str, ans))
