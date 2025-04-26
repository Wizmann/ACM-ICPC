class Solution(object):
    def earliestFullBloom(self, plantTime, growTime):
        plants = sorted(zip(growTime, plantTime))
        delta = 0
        ptr = min(growTime)
        qtr = max(growTime)
        for (g, p) in plants:
            ptr = max(ptr, g)
            u = min(p, qtr - ptr)
            delta += u
            ptr += u
        tot = sum(plantTime)
        tot = max(0, tot - delta)
        # print qtr, tot
        return qtr + tot
        
