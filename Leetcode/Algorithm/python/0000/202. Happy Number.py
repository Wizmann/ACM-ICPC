class Solution(object):
    def isHappy(self, n):
        s = set()
        while n != 1:
            if n in s:
                return False
            s.add(n)
            n = sum(map(lambda x: int(x) ** 2, str(n)))
        return True
