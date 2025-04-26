class Solution(object):
    def maxDistance(self, colors):
        d = {}
        maxi = 0
        for i, color in enumerate(colors):
            for (key, value) in d.items():
                if key == color:
                    continue
                maxi = max(maxi, i - value)
            if color not in d:
                d[color] = i
        return maxi
