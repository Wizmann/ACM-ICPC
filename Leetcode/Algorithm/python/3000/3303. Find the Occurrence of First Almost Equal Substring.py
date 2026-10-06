MOD = (1 << 61) - 1
ALPHA = 29
MAXN = 123456

pows = [1]
for i in xrange(1, MAXN):
    pows.append(pows[i - 1] * ALPHA % MOD)

class Solution(object):
    def minStartingIndex(self, s, pattern):
        h = 0
        m = len(pattern)
        for i in xrange(m):
            h = (h * ALPHA + ord(pattern[i]) - ord('a') + 1) % MOD
        chars = set(s)
        st = set([h])
        for i in xrange(m):
            for c in chars:
                hh = h
                hh -= (ord(pattern[i]) - ord('a') + 1) * pows[m - 1 - i]
                hh += (ord(c) - ord('a') + 1) * pows[m - 1 - i]
                hh = ((hh % MOD) + MOD) % MOD
                st.add(hh)
        n = len(s)
        h = 0
        for i in xrange(n):
            h = (h * ALPHA + ord(s[i]) - ord('a') + 1) % MOD
            if i - m >= 0:
                h -= (ord(s[i - m]) - ord('a') + 1) * pows[m]
                h = ((h % MOD) + MOD) % MOD
            if h in st:
                return i - m + 1
        return -1

############################

def z_function(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in xrange(1, n):
        if i <= r and z[i - l] < r - i + 1:
            z[i] = z[i - l]
        else:
            z[i] = max(0, r - i + 1)
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z

class Solution(object):
    def minStartingIndex(self, s, pattern):
        n = len(pattern)
        m = len(s)
        s1 = pattern + '#' + s
        z1 = z_function(s1)
        s2 = pattern[::-1] + '#' + s[::-1]
        z2 = z_function(s2)

        # bcdffg#abcdefg
        # gffdcb#gfedcba

        print z1, z2

        for i in xrange(n + 1, n + m + 1):
            a = z1[i]
            if a == len(pattern):
                return i - n - 1
            j = n + 1 + (m + n - (i + n - 1))
            b = z2[j]
            if j >= n + 1 and a + b >= n - 1:
                return i - n - 1
        return -1

'''
^^^^^^^^^TEST^^^^^^^^^
"jkjkkjjkjjkkjk"
"kkkkk"
-------------
-1
$$$$$$$$TEST$$$$

^^^^^^^^^TEST^^^^^^^^^
"abcdefg"
"bcdffg"
-------------
1
$$$$$$$$TEST$$$$
'''



