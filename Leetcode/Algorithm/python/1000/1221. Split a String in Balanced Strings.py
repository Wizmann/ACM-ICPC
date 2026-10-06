class Solution(object):
    def balancedStringSplit(self, s):
        st = []
        cnt = 0
        res = 0
        for c in s:
            st.append(c)
            if st[-1] == 'L':
                cnt -= 1
            else:
                cnt += 1
            if cnt == 0:
                res += 1
                st = []
        return res
