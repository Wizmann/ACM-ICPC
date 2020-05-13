import copy

def expand(mat, size):
    mat = mat.split("|")
    n = len(mat)
    m = len(mat[0])

    ret = [ ['X' for j in xrange(m * size)] for i in xrange(n * size)] 

    for i in xrange(n):
        for j in xrange(m):
            y = i * size
            x = j * size

            for ii in xrange(size):
                for jj in xrange(size):
                    ret[y + ii][x + jj] = mat[i][j]
    '''
    for line in ret:
        print ''.join(line)
    print '-'
    '''
    return ret

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

def dfs(mat, y, x):
    n = len(mat)
    m = len(mat[0])
    if mat[y][x] == '.':
        return 0
    mat[y][x] = '.'
    tot = 1
    for i in xrange(4):
        ny = y + my[i]
        nx = x + mx[i]
        if 0 <= ny < n and 0 <= nx < m and mat[ny][nx] != '.':
            tot += dfs(mat, ny, nx)
    return tot


d = {}

def do_check(exp, mat, y, x, maxi):
    n = len(mat)
    m = len(mat[0])
    en = len(exp)
    em = len(exp[0])

    mm = copy.deepcopy(mat)

    cnt = 0
    for i in xrange(n):
        for j in xrange(m):
            ny = i + y
            nx = j + x

            if ny >= en or nx >= em or exp[ny][nx] != mm[i][j]:
                mm[i][j] = '.'
            else:
                cnt += 1
    h = ''
    for line in mm:
        h += ''.join(line)
        h += '|'
    if h in d:
        return d[h]

    if cnt <= maxi:
        return 0

    '''
    for line in mm:
        print ''.join(line)
    print '-'
    '''

    res = 0
    for i in xrange(n):
        for j in xrange(m):
            if mm[i][j] == '.':
                continue
            ret = dfs(mm, i, j)
            cnt -= ret
            res = max(res, ret)
            if cnt <= max(maxi, res):
                break
        if cnt <= max(maxi, res):
            break
    d[h] = res
    return res

def check(exp, mat, maxi):
    en = len(exp)
    em = len(exp[0])

    res = 0
    for i in xrange(en - n):
        for j in xrange(em - m):
            res = max(res, do_check(exp, mat, i, j, maxi))
    return res

T = int(raw_input())

for case_ in xrange(T):
    (n, m) = map(int, raw_input().split())
    mat = [ list(raw_input()) for i in xrange(n) ]

    res = 0
    visited = set()
    for i in xrange(n):
        for j in xrange(m):
            cases = []
            cases.append( mat[i][j] + mat[i][j] + "|" + mat[i][j] + mat[i][j] )
            if j + 1 < m:
                cases.append(mat[i][j] + mat[i][j + 1] + "|" + mat[i][j] + mat[i][j + 1])
            if i + 1 < n:
                cases.append(mat[i][j] + mat[i][j] + "|" + mat[i + 1][j] + mat[i + 1][j])
            if j + 1 < m and i + 1 < n:
                cases.append(mat[i][j] + mat[i][j + 1] + "|" + mat[i + 1][j] + mat[i + 1][j + 1])
            for case in cases:
                if case in visited:
                    continue
                exp = expand(case, 20)
                res = max(res, check(exp, mat, res))
                visited.add(case)
    print 'Case #%d: %d' % (case_ + 1, res)

