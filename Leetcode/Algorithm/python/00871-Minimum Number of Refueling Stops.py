import heapq

class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        tank = []
        res = 0
        fuel = startFuel
        
        stations.append((target, 0))
        cur = 0
        for (pos, gas) in stations:
            delta = pos - cur
            while delta:
                used = min(fuel, delta)
                delta -= used
                fuel -= used
                
                if delta == 0:
                    break
                elif delta and tank:
                    fuel = -heapq.heappop(tank)
                    res += 1
                else:
                    return -1
            cur = pos
            heapq.heappush(tank, -gas)
        return res

            
        
        
