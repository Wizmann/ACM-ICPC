from collections import defaultdict

class Solution(object):
    def displayTable(self, orders):
        d = defaultdict(list)
        dishes = set()
        for (name, table, dish) in orders:
            d[int(table)].append(dish)
            dishes.add(dish)
        dishes = sorted(list(dishes))
        r_dishes = {}
        for i, dish in enumerate(dishes):
            r_dishes[dish] = i
        
        res = []
        res.append(['Table'] + dishes)
        tables = sorted(d.items())
        
        for (table, ordered) in tables:
            line = [table] + [0 for i in xrange(len(dishes))]
            
            for order in ordered:
                line[r_dishes[order] + 1] += 1
            res.append(map(str, line))
        return res
                
            
