class Solution(object):
    def reverseWords(self, s):
        s = s.split()
        cnt = 0
        for c in s[0]:
            if c in 'aeiou':
                cnt += 1

        for i in xrange(1, len(s)):
            sub = s[i]
            cnt1 = 0
            for c in sub:
                if c in 'aeiou':
                    cnt1 += 1
            if cnt == cnt1:
                s[i] = sub[::-1]

        return ' '.join(s)

