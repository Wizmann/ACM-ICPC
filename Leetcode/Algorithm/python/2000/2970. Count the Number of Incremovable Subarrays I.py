INF = 10 ** 100

class Solution(object):
    def incremovableSubarrayCount(self, nums):
        n = len(nums)
        n1 = [False for i in xrange(n)]
        n2 = [False for i in xrange(n)]
        
        pre = -INF
        for i, num in enumerate(nums):
            if num > pre:
                n1[i] = True
            if i - 1 >= 0:
                n1[i] = n1[i] and n1[i - 1]
            pre = num

        pre = INF
        for i, num in reversed(list(enumerate(nums))):
            if num < pre:
                n2[i] = True
            if i + 1 < n:
                n2[i] = n2[i] and n2[i + 1]
            pre = num
        res = 0
        for i in xrange(n):
            for j in xrange(i + 1, n + 1):
                ii = i - 1
                jj = j

                flag = True
                flag = flag and (ii < 0 or n1[ii])
                flag = flag and (jj >= n or n2[jj])

                left = -INF if ii < 0 else nums[ii]
                right = INF if jj >= n else nums[jj]
                flag = flag and (left < right)

                if flag:
                    # print i, j
                    res += 1
        return res
