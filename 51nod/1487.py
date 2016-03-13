def solve():
    (n, m, k) = map(int, raw_input().split())
    board = []
    
    for i in xrange(n):
        line = map(int, list(raw_input().strip()))
        board.append(line)
    
    dx, dy = [], []
    for i in xrange(k):
        y, x = map(int, raw_input().split())
        dx.append(x)
        dy.append(y)       
    
    score = [[0 for i in xrange(m)] for j in xrange(n)]
    
    in_board = lambda y, x: x >= 0 and x < m and y >= 0 and y < n
    
    def check(p0, p1):
        s = set([])
        y0, x0 = p0
        y1, x1 = p1
        
        for i in xrange(k):
            ny0, nx0 = y0 + dy[i], x0 + dx[i]
            ny1, nx1 = y1 + dy[i], x1 + dx[i]
            
            if in_board(ny0, nx0):
                s.add((ny0, nx0))
            if in_board(ny1, nx1):
                s.add((ny1, nx1))
        res = 0
        for point in s:
            y, x = point
            res += board[y][x]
        return res

    for i in xrange(n):
        for j in xrange(m):
            for idx in xrange(k):
                ny = i + dy[idx]
                nx = j + dx[idx]
                              
                if in_board(ny, nx):
                    score[i][j] += board[ny][nx]

    points = [] 
    ans = 0

    for i in xrange(n):
        for j in xrange(m):
            points.append((score[i][j], (i, j)))
            ans = max(ans, score[i][j])
    
    points.sort(key=lambda x: x[0], reverse=True)
    
    for i in xrange(n):
        for j in xrange(m):
            neighbors = set([(i, j)])
            for idx0 in xrange(k):
                ny = i + dy[idx0]
                nx = j + dx[idx0]
                if not in_board(ny, nx):
                    continue
                
                for idx1 in xrange(k):
                    yy = ny - dy[idx1]
                    xx = nx - dx[idx1]
                    if not in_board(yy, xx):
                        continue
                       
                    if yy == i and xx == j:
                        continue
                    
                    #print '>>', check((i, j), (yy, xx))
                    if score[i][j] + score[yy][xx] > ans:
                        ans = max(ans, check((i, j), (yy, xx)))
                    neighbors.add((yy, xx))
            
            for point in points:
                if point[1] in neighbors:
                    continue
                if point[1] == (i, j):
                    continue
                if score[i][j] + point[0] <= ans:
                    break
                #print '>>', score[i][j] + point[0]
                ans = max(ans, score[i][j] + point[0])
                break
    print ans

T = int(raw_input())

for case_ in xrange(T):
    solve()