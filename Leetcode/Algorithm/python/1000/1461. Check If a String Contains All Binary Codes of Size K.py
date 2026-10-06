class Solution(object):
    def hasAllCodes(self, s, k):
        n = len(s)
        st = set()
        for i in xrange(n - k + 1):
            bits = s[i: i + k]
            num = int(bits, 2)
            st.add(num)
        return len(st) == (1 << k)
            
