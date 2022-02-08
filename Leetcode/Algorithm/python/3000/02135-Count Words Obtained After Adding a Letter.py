from collections import defaultdict

class Solution(object):
    def wordCount(self, startWords, targetWords):
        st = set()
        for word in startWords:
            cur = 0
            for c in word:
                cur |= 1 << (ord(c) - ord('a'))
            st.add(cur)

        res = 0
        for word in targetWords:
            cur = 0
            for c in word:
                cur |= 1 << (ord(c) - ord('a'))
            for i in xrange(26):
                nxt = 1 << i
                if (cur & nxt) and (cur ^ nxt) in st:
                    res += 1
                    break
        return res

'''
^^^^TEST^^^
["ant","act","tack"]
["tack","act","acti"]
------
2
$$$TEST$$$

^^^^TEST^^^
["q","ugqm","o","ar","e"]
["nco","mnwhi","tkuw","ugmiq","fb","oykr","us","sra","dxg","dbp","ql","fq"]
------
4
$$$TEST$$$
'''

