class Solution(object):
    def diStringMatch(self, S):
        l, r = -1, 1
        res = [0]
        for c in S:
            if c == 'I':
                res.append(r)
                r += 1
            else:
                res.append(l)
                l -= 1
        mini = min(res)
        return map(lambda x: x - mini, res)
