class Solution(object):
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        opened = initialBoxes
        closed = set()
        tot = 0
        while opened:
            cur = opened.pop()
            tot += candies[cur]
            for key in keys[cur]:
                status[key] = 1
                if key in closed:
                    closed.remove(key)
                    opened.append(key)
            for box in containedBoxes[cur]:
                if status[box] == 1:
                    opened.append(box)
                else:
                    closed.add(box)
        return tot
                    
            
