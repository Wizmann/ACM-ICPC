from collections import Counter

class Solution(object):
    def maximumLength(self, nums):
        c = Counter(nums)
        maxi = 0
        if c[1]:
            maxi = c[1] - (c[1] + 1) % 2
        i = 2
        while i * i <= 1234567890:
            j = 1
            cnt = 1
            while True:
                if c[i ** j] == 0:
                    maxi = max(maxi, (cnt - 1) * 2 - 1)
                    break
                elif c[i ** j] == 1:
                    maxi = max(maxi, cnt * 2 - 1)
                    break
                else:
                    maxi = max(maxi, cnt * 2 - 1)
                j *= 2
                cnt += 1
            i += 1
        return maxi
