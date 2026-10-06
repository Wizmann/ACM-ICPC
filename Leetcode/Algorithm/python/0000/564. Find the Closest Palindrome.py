def makePalindrome(l, m):
    if l % 2 == 0:
        return int(str(m) + str(m)[::-1])
    else:
        return int(str(m) + str(m)[::-1][1:])

class Solution(object):
    def nearestPalindromic(self, n):
        n = int(n)
        s = str(n)
        m = int(s[:(len(s) + 1) / 2])
        
        a1 = makePalindrome(len(s), m)
        a2 = makePalindrome(len(s), m + 1)
        a3 = makePalindrome(len(s), m - 1)
        a4 = int('9' * len(s))
        a5 = int('9' * (len(s) - 1 if len(s) > 1 else 1))
        a6 = int('1' + '0' * (len(s) - 1) + '1')
        
        ans = -1
        mini = 10 ** 10
        for item in [a1, a2, a3, a4, a5, a6]:
            if item == n:
                continue
            if abs(n - item) < mini:
                ans = item
                mini = abs(n - item)
            elif abs(n - item) == mini:
                ans = min(ans, item)
        return str(ans)
