class Solution(object):
    def minimumChairs(self, s):
        maxi = 0
        cur = 0
        for c in s:
            if c == 'E':
                cur += 1
            else:
                cur -= 1
            maxi = max(maxi, cur)
        return maxi
