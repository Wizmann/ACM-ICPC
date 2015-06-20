n = int(raw_input())

mat = [[0 for i in xrange(111)] for j in xrange(111)]

for i in xrange(n):
    (x1, y1, x2, y2) = map(int, raw_input().split())
    
    for y in xrange(y1, y2 + 1):
        for x in xrange(x1, x2 + 1):
            mat[y][x] += 1
            
            
ans = 0

for i in xrange(111):
    for j in xrange(111):
        ans += mat[i][j]
        
print ans
