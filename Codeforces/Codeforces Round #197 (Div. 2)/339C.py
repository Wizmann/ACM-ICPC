import sys
sys.setrecursionlimit(555555)
from collections import defaultdict

s = raw_input()

ns = []
for i, c in enumerate(s):
    if c == '1':
        ns.append(i + 1)

n = len(ns)
m = int(raw_input())

dp = {}

def dfs(cur, diff, pre):
    if cur == m:
        return (cur, diff, pre)

    key = (cur, diff, pre)
    if key in dp:
        return dp[key]

    res = None
    for num in ns:
        #print cur, diff, pre, num, diff
        if num > diff and num != pre:
            res = dfs(cur + 1, num - diff, num)
            if res:
                break

    dp[key] = res
    return res


res = dfs(0, 0, -1)
if not res:
    print 'NO'
else:
    print 'YES'

    (cur, diff, pre) = res
    assert cur == m
    res = []
    while pre != -1:
        res.append(pre)
        cur -= 1
        diff = pre - diff
        for num in ns:
            if num != pre and (cur, diff, num) in dp:
                pre = num
                break
        else:
            pre = -1
        assert diff > 0 or pre == -1
    print ' '.join(map(str, res[::-1]))
