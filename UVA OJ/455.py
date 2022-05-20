#python3

def z_function(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r and z[i - l] < r - i + 1:
            z[i] = z[i - l]
        else:
            z[i] = max(0, r - i + 1)
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z

T = int(input())

for case_ in range(T):
    while True:
        s = input().strip()
        if s:
            break

    n = len(s)
    z = z_function(s)

    res = n
    for i, num in enumerate(z):
        u = n - num
        if n % u == 0:
            res = min(res, u)
    if case_:
        print('')
    print(res)

'''
^^^TEST^^^
2

abcabcabc

HoHoHo
------
3

2
$$$TEST$$$

'''


