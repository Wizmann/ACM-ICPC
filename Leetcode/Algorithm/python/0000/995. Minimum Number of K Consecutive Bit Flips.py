class Solution(object):
    def minKBitFlips(self, A, K):
        n = len(A)
        step = 0
        st = []
        for i in xrange(n):
            if st and st[0] < i:
                st.pop(0)
            u = len(st) % 2
            A[i] ^= u
            if A[i] == 0:
                if i + K - 1 >= n:
                    return -1
                st.append(i + K - 1)
                step += 1
        return step
