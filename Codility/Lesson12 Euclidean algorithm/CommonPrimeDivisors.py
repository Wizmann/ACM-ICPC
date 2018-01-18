def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def same_pfactor(a, b):
    g = gcd(a, b)
    while True:
        f = gcd(a, g)
        if f == 1:
            break
        a /= f
    
    while True:
        f = gcd(b, g)
        if f == 1:
            break
        b /= f
        
    return a == 1 and b == 1

def solution(A, B):
    n = len(A)
    ans = 0
    for i in range(n):
        ans += 1 if same_pfactor(A[i], B[i]) else 0
    return ans
