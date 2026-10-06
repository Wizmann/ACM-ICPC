class Solution(object):
    def findTheLongestBalancedSubstring(self, s):
        s += '9'
        pre = 'x'
        cnt = 0
        ss = []
        for c in s:
            if c == pre:
                cnt += 1
            else:
                if pre != 'x':
                    ss.append((pre, cnt))
                pre = c
                cnt = 1
        maxi = 0
        # print ss
        for i, (key, value) in enumerate(ss):
            if i == 0:
                continue
            if key == '1':
                if ss[i - 1][0] == '0':
                    maxi = max(maxi, 2 * min(value, ss[i - 1][1]))
        return maxi
