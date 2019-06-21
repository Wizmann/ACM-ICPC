from collections import defaultdict

class Solution(object):
    def largestValsFromLabels(self, values, labels, num_wanted, use_limit):
        d = defaultdict(list)
        for (v, l) in zip(values, labels):
            d[l].append(v)
        vs = []
        for key in d.keys():
            d[key].sort(reverse=True)
            vs += d[key][:use_limit]
        return sum(sorted(vs, reverse=True)[:num_wanted])
            
            
        
        
