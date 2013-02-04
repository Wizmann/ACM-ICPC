import sys

sys.stdin = open("d.txt")

def upper_bound(nums, x):
    l, r = 0, len(nums)-1
    while l <= r:
        mid = (l + r + 1) >> 1
        if nums[mid] > x:
            r = mid - 1
        else:
            l = mid + 1
    return l

if __name__ == "__main__":
    n, t = map(int,raw_input().split())
    dp = []
    for i in xrange(n):
        instr = raw_input().split()
        x = int(instr[0])
        if not dp:
            dp.append(x)
        else:
            if x >= dp[-1]:
                dp.append(x)
            else:
                dp[upper_bound(dp, x)] = x

    print n - len(dp)
