MOD = (10 ** 9) + 7
n = int(raw_input()) + 1

a = (pow(3, n, MOD) - 1 + MOD) % MOD
b = pow(2, MOD - 2, MOD)
print a * b % MOD
