class Solution(object):
    def addNegabinary(self, arr1, arr2):
        arr1 = arr1[::-1]
        arr2 = arr2[::-1]
        
        idx = 0
        g1, g2 = 0, 0
        res = []
        while idx < len(arr1) or idx < len(arr2) or g1 or g2:
            a = 0 if idx >= len(arr1) else arr1[idx]
            b = 0 if idx >= len(arr2) else arr2[idx]
            
            cur = a + b + g1
            #print idx, g1, g2, cur, res
            g1, g2 = g2, 0
            
            while cur < 0:
                g1 += 1
                cur += 2
            
            while cur >= 2:
                g1 -= 1
                cur -= 2
                
            res.append(cur)            
            
            idx += 1
            
        while res and res[-1] == 0:
            res.pop()
            
        if not res:
            res = [0]
        return res[::-1]
