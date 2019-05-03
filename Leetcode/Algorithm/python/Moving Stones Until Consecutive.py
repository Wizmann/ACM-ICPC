class Solution(object):
    def numMovesStones(self, a, b, c):
        a, b, c = sorted([a, b, c])
        ans1 = 0
        if a + 1 == b and b + 1 == c:
            ans1 = 0
        elif a + 1 == b or b + 1 == c or b + 2 == c or a + 2 == b:
            ans1 = 1
        else:
            ans1 = 2
            
        ans2 = (b - a - 1) + (c - 1 - b)
        return [ans1, ans2]
