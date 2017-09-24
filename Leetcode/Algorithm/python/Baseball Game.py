class Solution(object):
    def calPoints(self, ops):
        st = []
        for op in ops:
            if op == 'C':
                st.pop()
            elif op == 'D':
                st.append(st[-1] * 2)
            elif op == '+':
                st.append(st[-1] + st[-2])
            else:
                st.append(int(op))
        return sum(st)
