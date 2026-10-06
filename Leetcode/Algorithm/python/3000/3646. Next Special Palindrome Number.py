from collections import defaultdict

d = defaultdict(list)
def dfs(cur, n, cnt, pre):
    if sum(cnt.keys()) > n:
        return
    if cur == n:
        if pre == pre[::-1]:
            d[n].append(int(''.join(map(str, pre))))
        return
    for i in xrange(1, 10):
        if i in cnt and cnt[i] != 0:
            pre.append(i)
            cnt[i] -= 1
            if cur < (n + 1) / 2 or pre[cur] == pre[n - 1 - cur]:
                dfs(cur + 1, n, cnt, pre)
            pre.pop()
            cnt[i] += 1
        elif i not in cnt:
            cnt[i] = i - 1
            pre.append(i)
            if cur < (n + 1) / 2 or pre[cur] == pre[n - 1 - cur]:
                dfs(cur + 1, n, cnt, pre)
            pre.pop()
            del cnt[i]

for i in xrange(1, 17):
    pre = []
    cnt = {}
    dfs(0, i, cnt, pre)
values = sum(d.values(), [])
values.sort()

class Solution(object):
    def specialPalindrome(self, n):
        l, r = 0, len(values) - 1
        while l <= r:
            m = (l + r) / 2
            if values[m] <= n:
                l = m + 1
            else:
                r = m - 1
        return values[l]
