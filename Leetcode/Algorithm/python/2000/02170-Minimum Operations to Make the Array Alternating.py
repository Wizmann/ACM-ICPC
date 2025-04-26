INF = 10 ** 10

from collections import Counter

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        evens = nums[::2]
        odds = nums[1::2]
        
        ce = Counter(evens)
        tope = sorted(ce.items(), key=lambda x: x[1], reverse=True)[:2] + [(INF, 0)]
        co = Counter(odds)
        topo = sorted(co.items(), key=lambda x : x[1], reverse=True)[:2] + [(-INF, 0)]
        
        res = INF
        for key, value in ce.items():
            mini = INF
            cost = len(evens) - value
            for key_o, value_o in topo:
                if key_o != key:
                    mini = min(mini, cost + len(odds) - value_o)
            res = min(mini, res)
        return res
                    
