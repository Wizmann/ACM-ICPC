class Solution(object):
    def minimumCost(self, start, target, specialRoads):
        self.start = start
        self.target = target
        self.dis = {}
        
        q = [start]
        
        while q:
            x, y = q.pop(0)
            for (x1, y1, x2, y2, cost) in specialRoads:
                d1 = self.dis.get((x, y), self.get_dis(start, (x, y))) + self.get_dis((x, y), (x1, y1))
                d = d1 + cost
                if d < self.dis.get((x2, y2), self.get_dis(start, (x2, y2))):
                    self.dis[(x2, y2)] = d
                    q.append((x2, y2))
        
        mini = self.get_dis(start, target)
        for p, v in self.dis.items():
            mini = min(mini, v + self.get_dis(p, target))
        return mini
        
    def get_dis(self, p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
