class Solution(object):
    def buildArray(self, target, n):
        st = []
        res = []
        ptr = 0
        for i in xrange(1, n + 1):
            if st == target:
                continue
            st.append(i)
            res.append('Push')
            if st[-1] == target[ptr]:
                ptr += 1
            else:
                st.pop()
                res.append('Pop')
        return res
