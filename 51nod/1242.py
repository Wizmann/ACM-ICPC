MOD = 1000000009

def matrix_mul(m1, m2):
    m3 = [ [0, 0], [0, 0] ]
    m3[0][0] = (m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0]) % MOD
    m3[0][1] = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % MOD
    m3[1][0] = (m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0]) % MOD
    m3[1][1] = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % MOD
    return m3
    
n = int(raw_input()) - 1

a = [ [0, 1], [1, 1] ]
b = [ [1, 0], [0, 1] ]
while n:
    if n & 1:
        b = matrix_mul(b, a)
    n >>= 1
    a = matrix_mul(a, a)
c = [ [1, 1], [0, 0] ]
d = matrix_mul(c, b)

print d[0][0] % MOD
