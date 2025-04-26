class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        A, B = [], []
        n = len(customers)
        
        for i in xrange(n):
            A.append(customers[i] * (grumpy[i] ^ 1))
            B.append(customers[i] * grumpy[i])

        res = sum(A)
        X = min(X, n)
        
        delta = sum(B[:X])
        maxi = delta
        for i in xrange(X, n):
            delta = delta - B[i - X] + B[i]
            maxi = max(maxi, delta)
        return res + maxi

        
