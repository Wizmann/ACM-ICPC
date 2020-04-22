class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        d = dict(zip('croak', range(5)))
        ps = [0, 0, 0, 0, 0]
        
        for c in croakOfFrogs:
            cur = d[c]
            pre = (cur + 4) % 5
            if ps[pre]:
                ps[pre] -= 1
                ps[cur] += 1
            elif c == 'c':
                ps[cur] += 1
            else:
                return -1
            
        if sum(ps) != ps[-1]:
            return -1
        return ps[-1]
