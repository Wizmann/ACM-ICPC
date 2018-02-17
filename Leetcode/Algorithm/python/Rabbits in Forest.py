from collections import Counter

class Solution(object):
    def numRabbits(self, answers):
        c = Counter(answers)
        ans = 0
        for (key, value) in c.items():
            ans += (value + key) / (key + 1) * (key + 1)
        return ans
