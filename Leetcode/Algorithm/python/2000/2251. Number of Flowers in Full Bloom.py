E_CHANGE_FLOWER = 1
E_OBSERVE = 2

class Event(object):
    def __init__(self, tp, val, time):
        self.tp = tp
        self.val = val
        self.time = time

class Solution(object):
    def fullBloomFlowers(self, flowers, persons):
        events = []
        
        for (st, end) in flowers:
            events.append(Event(E_CHANGE_FLOWER, 1, st))
            events.append(Event(E_CHANGE_FLOWER, -1, end + 1))
        
        for i, p in enumerate(persons):
            events.append(Event(E_OBSERVE, i, p))
            
        events.sort(key=lambda e: (e.time, e.tp))
        
        tot = 0
        res = [0 for i in xrange(len(persons))]
        for e in events:
            if e.tp == E_CHANGE_FLOWER:
                tot += e.val
            elif e.tp == E_OBSERVE:
                res[e.val] = tot
        return res
                
