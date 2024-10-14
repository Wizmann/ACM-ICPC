#python3

MOD = 998244353

def inv(x):
    return pow(x, MOD - 2, MOD)

n = int(input())

Q = pow(6, n, MOD)
P = pow(6, (n + 1) // 2, MOD)

print(P * inv(Q) % MOD)

'''
^^^^TEST^^^^^
3
-----------
166374059
$$$TEST$$$$
'''
