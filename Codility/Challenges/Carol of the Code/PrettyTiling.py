#python3

INF = 10 ** 100
xrange = range

def rotate(t):
    assert(len(t) == 4)
    return t[1:4] + t[0]

assert rotate('ABCD') == 'BCDA'

def do_solve(pre, A):
    n = len(A)
    res = 0
    for i in xrange(n):
        cur = A[i][:]
        for j in xrange(4):
            u = cur[3]
            if pre == u:
                res += min(j, 4 - j)
                break
            else:
                cur = rotate(cur)
        else:
            assert(False)
        pre = cur[1]
    return res

def solution(A):
    # write your code in Python 3.8.10

    mini = INF
    for pre in 'RGBW':
        mini = min(mini, do_solve(pre, A))
    return mini

assert solution(["RGBW", "GBRW"]) == 1
assert solution(["WBGR", "WBGR", "WRGB", "WRGB", "RBGW"]) == 4
