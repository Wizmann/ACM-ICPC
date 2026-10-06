ALPHA = 26

def char_to_int(c):
    return ord(c) - ord('a')

class Solution(object):
    def maxNumOfSubstrings(self, s):
        n = len(s)
        pos = [[] for i in xrange(ALPHA)]
        
        for i, c in enumerate(s):
            c = char_to_int(c)
            if pos[c]:
                pos[c][1] = i
            else:
                pos[c] = [i, i]

        segs = []
        for i in xrange(ALPHA):
            if not pos[i]:
                continue
            l, r = pos[i]
            while True:
                flag = False
                for c in s[l: r + 1]:
                    c = char_to_int(c)
                    lc, rc = pos[c]
                    if lc < l or rc > r:
                        l, r = min(lc, l), max(rc, r)
                        flag = True
                if not flag:
                    break
            segs.append((l, r))
        segs.sort(key=lambda (l, r): r)
        ans = []
        for seg in segs:
            if not ans or seg[0] > ans[-1][1]:
                ans.append(seg)
        return map(lambda (l, r): s[l: r + 1], ans)
