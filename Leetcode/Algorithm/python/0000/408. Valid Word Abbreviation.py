class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        p, q = 0, 0
        n, m = len(word), len(abbr)
        
        while p < n and q < m:
            if word[p] == abbr[q]:
                p += 1
                q += 1
            elif abbr[q].isdigit():
                u = 0
                while q < m and abbr[q].isdigit():
                    if u == 0 and int(abbr[q]) == 0:
                        return False
                    u = u * 10 + int(abbr[q])
                    q += 1
                p += u
                if p > n:
                    return False
            else:
                return False
        return p == n and q == m
        
