class Solution(object):
    def alphabetBoardPath(self, target):
        p = 0
        res = ''
        for c in target:
            q = ord(c) - ord('a')
            while p != q:
                l, r = (p / 5) * 5, (p / 5 + 1) * 5 - 1
                if q == 25 and p % 5 != 0:
                    p -= 1
                    res += 'L'
                elif l <= min(p, q) <= max(p, q) <= r:
                    if p < q:
                        p += 1
                        res += 'R'
                    else:
                        p -= 1
                        res += 'L'
                else:
                    if p < q:
                        p += 5
                        res += 'D'
                    else:
                        p -= 5
                        res += 'U'
            res += '!'
        return res
