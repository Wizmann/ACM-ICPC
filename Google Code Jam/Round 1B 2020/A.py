# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62

T = int(raw_input())
for case_ in xrange(T):
    x, y = map(int, raw_input().split())
    res = []
    while x or y:
        # print x, y
        flag = False
        if x == 1 and y == 0:
            res.append('E')
            break
        elif x == -1 and y == 0:
            res.append('W')
            break
        elif x == 0 and y == 1:
            res.append('N')
            break
        elif x == 0 and y == -1:
            res.append('S')
            break
        elif ((x % 2) ^ (y % 2)) == 0:
            res = []
        elif x % 2 == 1:
            nx = (x + 1) / 2
            ny = y / 2
            if ((nx % 2) ^ (ny % 2)):
                flag = True
                x, y = nx, ny
                res.append('W')
                continue

            nx = (x - 1) / 2
            ny = y / 2
            if ((nx % 2) ^ (ny % 2)):
                flag = True
                x, y = nx, ny
                res.append('E')
                continue
        else:
            nx = x / 2
            ny = (y - 1) / 2
            if ((nx % 2) ^ (ny % 2)):
                flag = True
                x, y = nx, ny
                res.append('N')
                continue

            nx = x / 2
            ny = (y + 1) / 2
            if ((nx % 2) ^ (ny % 2)):
                flag = True
                x, y = nx, ny
                res.append('S')
                continue
        if flag == False:
            res = []
            break
    if not res:
        print 'Case #%d: %s' % (case_ + 1, 'IMPOSSIBLE')
    else:
        print 'Case #%d: %s' % (case_ + 1, ''.join(res))
