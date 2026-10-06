class Solution(object):
    def constructRectangle(self, area):
        i = 1
        ans = (0, 0)
        mindiff = 10 ** 10
        while i * i <= area:
            if area % i != 0:
                i += 1
                continue
            a, b = i, area / i
            if abs(a - b) < mindiff:
                ans = (a, b)
                mindiff = abs(a - b)
            i += 1
        return [max(ans), min(ans)]
                
