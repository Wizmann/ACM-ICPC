class Solution(object):
    def smallestString(self, s):
        s = list(s)
        pre = True
        for i, c in enumerate(s):
            if c == 'a':
                if pre == False:
                    break
            else:
                pre = False
                s[i] = chr(ord(c) - 1)
        if pre == True:
            s[-1] = 'z'
        return ''.join(s)
