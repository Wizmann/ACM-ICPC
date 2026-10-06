class Solution(object):
    def minDeletionSize(self, A):
        n = len(A[0])
        st = []
        for i in xrange(n):
            st.append(''.join(map(lambda x: x[i], A)))
            
        res = 0
        for s in st:
            if s != ''.join(sorted(s)):
                res += 1
        return res 
