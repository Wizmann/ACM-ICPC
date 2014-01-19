SIZE = 1000000
LEN = 3 * SIZE

dp = [-1 for i in xrange(LEN)]

def gao(v):
    nn = v / 2 if v % 2 == 0 else 3 * v + 1
    
    if v >= LEN or nn >= LEN:
        u = gao(nn)
    elif dp[nn] == -1:
        u = gao(nn)
        dp[v] = u + 1
    else:
        u = dp[nn]
        dp[v] = u + 1
    return u + 1

def main():
    dp[1] = 1
    ans = 0
    uu = 0
    for i in xrange(2, SIZE + 1):
        u = gao(i)
        if u > ans:
            ans = u
            uu = i
    print uu

main()
