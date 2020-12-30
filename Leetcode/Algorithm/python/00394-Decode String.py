class Solution(object):
    def decodeString(self, s):
        r = 0
        sub = None
        res = ''
        cnt = 0
        for c in s:
            if c.isdigit():
                if sub is not None:
                    sub += c
                else:
                    r = r * 10 + int(c)
            elif c == '[':
                if sub is not None:
                    sub += c
                else:
                    sub = ''
                cnt += 1
            elif c == ']':
                cnt -= 1
                if cnt == 0:
                    res += r * self.decodeString(sub)
                    r = 0
                    sub = None
                else:
                    sub += c
            else:
                if sub is not None:
                    sub += c
                else:
                    res += c
        return res
