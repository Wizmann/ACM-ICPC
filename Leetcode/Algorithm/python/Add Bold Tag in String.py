INF = 10 ** 10

def find_all(haystack, needle):
    k = 0
    while True:
        k = haystack.find(needle, k)
        if k == -1:
            break
        else:
            yield k
            k += 1

class Solution(object):
    def addBoldTag(self, s, dict):
        intervals = []
        for word in dict:
            matches = [(i, i + len(word)) for i in find_all(s, word)]
            intervals += matches
        
        print intervals    
            
        intervals = self.merge_intervals(intervals)
        l = 0
        res = ''
        
        print intervals
        for interval in intervals:
            ll, rr = interval
            if ll >= l:
                res += s[l:ll]
            res += '<b>%s</b>' % s[ll: rr]
            l = rr
        if l != len(s):
            res += s[l:]
        return res
        
    def merge_intervals(self, intervals):
        res = []
        intervals.sort()
        intervals.append( (INF, INF) )
        #print intervals
        l, r = -INF, -INF
        for interval in intervals:
            ll, rr = interval
            if ll > r:
                #print ll, rr
                if l != -INF:
                    res.append((l, r))
                l, r = ll, rr
            else:
                r = max(r, rr)
        return res
