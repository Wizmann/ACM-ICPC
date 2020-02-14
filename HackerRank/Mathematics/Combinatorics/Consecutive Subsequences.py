# https://www.hackerrank.com/challenges/consecutive-subsequences/problem

from collections import defaultdict

T = int(input())

def solve(ns, k):
    n = len(ns)
    d = defaultdict(int)
    d[0] += 1
    pre = 0
    tot = 0
    for i, num in enumerate(ns):
        pre += num
        pre %= k
        tot += d[pre]
        d[pre] += 1
    return tot

for case_ in range(T):
    (n, k) = map(int, input().split())
    ns = list(map(int, input().split()))

    print(solve(ns, k))
