from collections import defaultdict

class Solution(object):
    def splitPainting(self, segments):
        events = defaultdict(list)
        for (st, end, color) in segments:
            events[st].append(color)
            events[end].append(-color)
            
        events = sorted(events.items())
        cur = 0
        pre = -1
        res = []
        for (t, colors) in events:
            if pre > 0 and cur:
                res.append([pre, t, cur])
            for c in colors:
                cur += c
            pre = t
        return res
        
