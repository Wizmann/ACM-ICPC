class Solution(object):
    def getLucky(self, s, k):
        num = int(''.join(map(lambda x: str(ord(x) - ord('a') + 1), s)))
        for i in xrange(k):
            num = self.transform(num)
        return num
        
    def transform(self, num):
        num = str(num)
        return sum(map(int, num))
