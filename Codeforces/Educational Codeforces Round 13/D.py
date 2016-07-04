#coding=utf-8
MOD = (10 ** 9) + 7
(A, B, n, x) = map(int, raw_input().split())

res0 = pow(A, n, MOD) * x % MOD
if A == 1:
    res1 = B * n % MOD
else:
    res1 = (pow(A, n, MOD) - 1) * pow(A - 1, MOD - 2, MOD) * B % MOD

#print res0, res1
print (res0 + res1) % MOD

