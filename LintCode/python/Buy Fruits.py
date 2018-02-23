from collections import Counter

class Solution:
    """
    @param codeList: The codeList
    @param shoppingCart: The shoppingCart
    @return: The answer
    """
    def buyFruits(self, codeList, shoppingCart):
        d = { "anything": -1 }
        idx = 0
        src = []
        for fruitList in codeList:
            for fruit in fruitList:
                if fruit not in d:
                    d[fruit] = idx
                    idx += 1
                src.append(d[fruit])
                
        target = []
        for fruit in shoppingCart:
            if fruit not in d:
                d[fruit] = idx
                idx += 1
            target.append(d[fruit])
            
        n = len(src)
        m = len(target)

        for i in xrange(m - n + 1):
            p = 0
            q = i
            while p < n and q < m:
                if src[p] != target[q] and src[p] != -1:
                    break
                p += 1
                q += 1
                
            if p == n:
                return 1
        return 0
            
