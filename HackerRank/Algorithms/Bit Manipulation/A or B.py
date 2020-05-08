
def solve(A, B, C, k):
    maxlen = max(len(A), len(B), len(C))
    A = [0] * (maxlen - len(A)) + list(A)
    B = [0] * (maxlen - len(B)) + list(B)
    C = [0] * (maxlen - len(C)) + list(C)
    # print A, B, C
    n = len(A)
    for i in xrange(n - 1, -1, -1):
        a = int(A[i], 16)
        b = int(B[i], 16)
        c = int(C[i], 16)
        # print a, b, c, k

        for j in xrange(4):
            aa = a & (1 << j)
            bb = b & (1 << j)
            cc = c & (1 << j)

            # print aa, bb, cc

            if cc == 0 and (aa or bb):
                if aa:
                    k -= 1
                    a ^= 1 << j
                if bb:
                    k -= 1
                    b ^= 1 << j
            elif cc and (aa + bb == 0):
                b ^= 1 << j
                k -= 1
        if k < 0:
            return (-1, -1)
        A[i] = '%X' % a
        B[i] = '%X' % b
        # print a, b, c, k
        # print '--'
        assert (a | b) == c

    # print A, B, k

    for i in xrange(n):
        a = int(A[i], 16)
        b = int(B[i], 16)
        c = int(C[i], 16)

        for j in xrange(4, -1, -1):
            aa = a & (1 << j)
            bb = b & (1 << j)
            cc = c & (1 << j)

            if cc and aa and bb and k >= 1:
                a ^= 1 << j
                k -= 1
            elif cc and (aa and not bb) and k >= 2:
                a ^= 1 << j
                b ^= 1 << j
                k -= 2

        A[i] = '%X' % a
        B[i] = '%X' % b

        if k <= 0:
            break


    A = A[::-1]
    while A and A[-1] == '0':
        A.pop()
    A = A[::-1]

    B = B[::-1]
    while B and B[-1] == '0':
        B.pop()
    B = B[::-1]

    if not A:
        A = ['0']
    if not B:
        B = ['0']

    return ''.join(A), ''.join(B)

T = int(raw_input())

for case_ in xrange(T):
    k = int(raw_input())

    A = raw_input()
    B = raw_input()
    C = raw_input()

    (A1, B1) = solve(A, B, C, k)
    if A1 == -1:
        print A1
    else:
        print A1
        print B1
