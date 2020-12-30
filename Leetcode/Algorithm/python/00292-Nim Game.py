'''
def mex(l):
    i = 0
    while True:
        if i not in l:
            return i
        i += 1

class Solution(object):
    def canWinNim(self, n):
        sg = [0]
        for i in xrange(1, n + 1):
            l = []
            for j in [1, 2, 3]:
                if i - j >= 0:
                    #print i - j
                    l.append(sg[i - j])
            #print i, l, mex(l)
            sg.append(mex(l))
        #print sg
        return sg[-1] != 0


S = Solution()

for i in xrange(100):
    print i, S.canWinNim(i)
'''

class Solution(object):
    def canWinNim(self, n):
        return n % 4 != 0
