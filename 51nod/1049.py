INF = 0xdeadbeef

def max_subarray(nums):
    res = -INF
    s = 0
    for num in nums:
        s += num
        res = max(res, s)
        if s < 0:
            s = 0
    return res

n = int(raw_input())
nums = [int(raw_input()) for i in xrange(n)]

print max_subarray(nums)
