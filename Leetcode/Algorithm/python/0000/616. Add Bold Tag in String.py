import re

class Solution(object):
    def addBoldTag(self, s, dict):
        n = len(s)
        bold = [False for i in xrange(n)]
        for word in dict:
            for m in re.finditer(r"(?=%s)" % word, s):
                l, r = m.span()
                r += len(word)
                bold[l: r] = [True for i in xrange(r - l)]
        res = ""
        pre = False
        for i in xrange(n):
            if bold[i] == True:
                if pre == True:
                    res += s[i]
                else:
                    res += "<b>" + s[i]
                pre = True
            else:
                if pre == False:
                    res += s[i]
                else:
                    res += "</b>" + s[i]
                pre = False
        if pre:
            res += "</b>"
        return res
