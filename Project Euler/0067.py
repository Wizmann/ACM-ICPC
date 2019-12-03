import sys

INF = 10 ** 10
pre = []
for i, line in enumerate(sys.stdin):
    nums = map(int, line.split())
    if i == 0:
        pre = nums
    else:
        n = len(nums)
        for j in xrange(n):
            p = max(-INF if j - 1 < 0 else pre[j - 1], -INF if j == n - 1 else pre[j])
            nums[j] += p
        pre = nums
print max(pre)

