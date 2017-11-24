import sys

N = 5 * (10 ** 6) + 1

sys.setrecursionlimit(N)

d = [-1 for i in xrange(N)]
def dfs(n):
    if n < N and d[n] != -1:
        return d[n]
    if n == 1:
        return 0
    if n % 2 == 0:
        res = dfs(n / 2) + 1
    else:
        res = dfs(n * 3 + 1) + 1
    if n < N:
        d[n] = res
    return res

pre = [0]
maxi, ptr = 1, 1
for i in xrange(1, 5000001):
    u = dfs(i)
    if u >= maxi:
        maxi = u
        ptr = i
    pre.append(ptr)

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print pre[n]
