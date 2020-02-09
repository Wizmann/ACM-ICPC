# https://codeforces.com/problemset/problem/276/D
a, b = map(int, input().split())

c = a ^ b
if c == 0:
    print(0)
else:
    l = len('{:b}'.format(c))
    print((1 << l) - 1)

