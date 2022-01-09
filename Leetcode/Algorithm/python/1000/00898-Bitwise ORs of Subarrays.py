class Solution(object):
    def subarrayBitwiseORs(self, A):
        res = set()
        cur = set()
        
        for a in A:
            cur = set(map(lambda x: x | a, cur))
            cur.add(a)
            
            res |= cur
        return len(res)
