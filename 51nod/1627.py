MAX_K = 111111
MOD = 1000000007

rev = [pow(i, MOD - 2, MOD) for i in range(MAX_K)]

L = [ [1, 1], [1, 1] ]

def C(a, b, pre):
    A, B = L[pre]
    #print a, b, pre
    if b == 0:
        return 1
    A = (A * (a - b + 1)) % MOD
    B = (B * rev[b]) % MOD
    L[pre] = [A, B]
    return (A * B) % MOD

def solve(n, m, k):
    #print L
    return (C(n - 2, k - 1, 0) * C(m - 2, k - 1, 1)) % MOD

(n, m) = map(int, raw_input().split())
max_k = min(MAX_K, n - 1, m - 1)

ans = 0
for i in range(1, max_k + 1):
    #print i
    ans = (ans + solve(n, m, i)) % MOD
    
print ans
