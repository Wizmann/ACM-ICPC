from collections import Counter

class Solution(object):
    def minimumRounds(self, tasks):
        tot = 0
        c = Counter(tasks)
        for key, value in c.items():
            if value == 1:
                return -1
            tot += value / 3
            if value % 3:
                tot += 1
        return tot
        
