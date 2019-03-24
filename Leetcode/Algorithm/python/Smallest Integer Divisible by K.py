class Solution(object):
    def smallestRepunitDivByK(self, K):
        st = set()
        rem = 0
        step = 0
        while True:
            rem = (rem * 10 + 1) % K
            step += 1
            if rem == 0:
                return step
            if rem in st:
                return -1
            st.add(rem)
