class Solution(object):
    def minOperations(self, logs):
        st = []
        for log in logs:
            if log == './':
                continue
            elif log == '../':
                if st:
                    st.pop()
            else:
                st.append(log)
        return len(st)
