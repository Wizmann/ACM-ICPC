# http://codeforces.com/contest/1313/problem/B

T = int(input())
for case_ in range(T):
    n, a, b = map(int, input().split())
 
    tot = (n - a + 1) + (n - b + 1)
 
    l = min(n, max(0, n - (tot - 2)) + 1)
    r = min(n, n - (tot - n) + 1)
    print(l, r)
