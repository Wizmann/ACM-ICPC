class Solution(object):
    def getSmallestString(self, n, k):
        for i in xrange(n):
            head = (i + 1) * 1
            tail = (k - head) / 26
            rem = (k - head) % 26
            
            if i + tail + (1 if rem else 0) == n:
                print head, rem, tail
                s = 'a' * i
                s += '' if rem == 0 else chr(ord('a') + rem)
                s += tail * 'z'
                break
        return s
