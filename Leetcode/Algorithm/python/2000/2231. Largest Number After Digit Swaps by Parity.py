class Solution(object):
    def largestInteger(self, num):
        ns = map(int, str(num))
        evens = sorted(filter(lambda x: x % 2 == 0, ns))
        odds = sorted(filter(lambda x : x % 2 == 1, ns))
        
        res = 0
        for num in ns:
            if num % 2 == 0:
                res = res * 10 + evens.pop()
            else:
                res = res * 10 + odds.pop()
        return res
