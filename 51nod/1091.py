n = int(raw_input())
ns = [map(int, raw_input().split()) for i in xrange(n)]

ns.sort()

maxi = 0
ans = 0

for i in xrange(n):
    st  = ns[i][0]
    end = ns[i][1]
    
    ans = max(ans, min(end, maxi) - st)
    maxi = max(maxi, end)
    
print ans
