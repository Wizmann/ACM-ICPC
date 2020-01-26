(n, k) = map(int, raw_input().split())
hs = map(int, raw_input().split())
 
hs.sort()
 
while hs and k:
    hs.pop()
    k -= 1
 
print sum(hs)
