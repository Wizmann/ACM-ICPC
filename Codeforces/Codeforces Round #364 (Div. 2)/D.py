#coding=utf-8
import sys
eps = 1e-6

def solve(n, l, v1, v2):
    t2 = 1.0 * (v1 + v2) * l / (n * (v1 + v2) * v2 - (n - 1) * v2 * (v2 - v1))
    l2 = v2 * t2
    l1 = l - l2
    t1 = l1 / v1
    #print(t1, l1, t2, l2)
    return t1 + t2

#print(solve(3, 6, 1, 2))
#print(solve(1, 10, 1, 2))

n, t, v1, v2, k = map(int, input().split())
n = (n + k - 1) // k

print(solve(n, t, v1, v2))
