from utils.prime.primes1m import primes
from math import sqrt

'''
Pell Equation

x^2 - D * y^2 == 1

若n是完全平方数，则这个方程式只有平凡解 (1, 0) (-1, 0)
若非完全平方数，则可以使用下面方法求x最小的解。

'''

def pell(d):
    p, k, x1, y, sd = 1, 1, 1, 0, sqrt(d)
 
    while k != 1 or y == 0:
        p = k * (p/k+1) - p
        p = p - int((p - sd)/k) * k
 
        x = (p*x1 + d*y) / abs(k)
        y = (p*y + x1) / abs(k)
        k = (p*p - d) / k
        x1 = x
    return x
 
L = 1000
print max(
    (pell(d),d) 
    for d in filter(lambda x: x <= L, primes))
