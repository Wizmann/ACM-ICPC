MOD = 0xdeadbeef

class Solution(object):
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        s = '#' + s
        maxi = 0
        size = minSize
        
        h = 0
        head = pow(29, size, MOD)
        d = {}
        l = {}
        for j in xrange(len(s)):
            h = (h * 29 + ord(s[j]) - ord('a') + 1) % MOD
            l[s[j]] = l.get(s[j], 0) + 1
            if j - size >= 0:
                h -= (ord(s[j - size]) - ord('a') + 1) * head % MOD
                h = (h % MOD + MOD) % MOD
                #print h
                l[s[j - size]] -= 1
                if l[s[j - size]] == 0:
                    del l[s[j - size]]
                    
                if len(l) <= maxLetters:
                    d[h] = d.get(h, 0) + 1
        if d:
            maxi = max(maxi, max(d.values()))
        return maxi
