class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        s = sum(filter(lambda x: x % 2 == 0, A))
        res = []
        for (v, k) in queries:
            before = A[k]
            after = A[k] + v
            
            if before % 2 == 0:
                s -= before
            if after % 2 == 0:
                s += after
                
            A[k] = after
            res.append(s)
        return res
