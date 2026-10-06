class Solution(object):
    def maxActiveSectionsAfterTrade(self, s):
        base = sum(map(int, s))
        s = '1' + s + '1$'
        gs = []
        pre = 'sign, machine'
        cnt = -1
        for c in s:
            if c != pre:
                if pre in '01':
                    gs.append([pre, cnt])
                pre, cnt = c, 1
            else:
                cnt += 1
                
        gs[0][1] -= 1
        gs[-1][1] -= 1
        m = len(gs)
        maxi = base
        # print gs
        for i in xrange(1, m - 1):
            if gs[i][0] == '0':
                continue
            a, b = gs[i - 1], gs[i + 1]
            # print a, b, gs[i]
            assert(a[0] == '0' and b[0] == '0')
            maxi = max(maxi, base + a[1] + b[1])
            
        return maxi
            
