from collections import defaultdict

class Solution(object):
    def minInsertions(self, s):
        st = []
        cnt = 0
        ahead = None
        for c in s:
            if c == '(':
                if ahead:
                    cnt += 1
                    st.append(")")
                st.append("(")
                ahead = None
            else:
                if ahead:
                    st.append(")")
                    ahead = None
                else:
                    ahead = ")"
        if ahead:
            cnt += 1
            st.append(")")
        st2 = []
        for c in st:
            if c == '(':
                st2.append(c)
            else:
                if st2 and st2[-1] == '(':
                    st2.pop()
                else:
                    cnt += 1
        return cnt + len(st2) * 2
        
assert Solution().minInsertions("(()))(()))()())))") == 4
assert Solution().minInsertions("((") == 4
assert Solution().minInsertions("(()") == 3
assert Solution().minInsertions(")") == 2
assert Solution().minInsertions(")(") == 4
assert Solution().minInsertions("(()))") == 1
assert Solution().minInsertions("())") == 0
assert Solution().minInsertions("))())(") == 3
assert Solution().minInsertions("((((((") == 12
assert Solution().minInsertions(")))))))") == 5
