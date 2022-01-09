class Solution(object):
    def judgePoint24(self, nums):
        st = [nums]
        while st:
            cur = st.pop()
            if len(cur) == 1:
                if abs(cur[0] - 24.0) < 1e-6:
                    return True
                continue
            
            m = len(cur)
            for i in xrange(m):
                for j in xrange(m):
                    if i == j:
                        continue
                    next = cur[:]
                    a, b = next[i], next[j]
                    del next[max(i, j)]
                    del next[min(i, j)]
                    
                    st.append(next + [a + b])
                    st.append(next + [a - b])
                    st.append(next + [a * b])
                    if b:
                        st.append(next + [1.0 * a / b])
        return False
