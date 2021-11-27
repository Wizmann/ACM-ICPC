
def solve(A, B):
    A = map(int, A[::-1])
    B = map(int, B[::-1])
    n = max(len(A), len(B))

    g = 0
    flag = False
    i = 0
    C = []
    while i < n or g:
        aa = 0 if i >= len(A) else A[i]
        bb = 0 if i >= len(B) else B[i]
        cur = (aa + bb + g) % 10
        g = (aa + bb + g) / 10
        if g:
            flag = True
        C.append(cur)
        i += 1
    return flag, ''.join(map(str, C[::-1]))

assert solve('123347234987', '982374891237423897939487')[1] == '982374891237547245174474'

A, B = raw_input().split()

flag, _ = solve(A, B)

if flag:
    print 'Hard'
else:
    print 'Easy'

'''
^^^TEST^^^
229 390
-----
Hard
$$$TEST$$$


^^^TEST^^^^
123456789 9876543210
------
Easy
$$$TEST$$$$
'''


