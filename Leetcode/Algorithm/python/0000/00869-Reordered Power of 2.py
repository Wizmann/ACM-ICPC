def sortedstr(s):
    return ''.join(sorted(str(s)))

s = set()
for i in xrange(64):
    s.add(sortedstr(1 << i))

class Solution(object):
    def reorderedPowerOf2(self, N):
        return sortedstr(N) in s
