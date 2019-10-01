class Solution(object):
    def removeDuplicates(self, s, k):
        st = []
        for c in s:
            if not st:
                st.append([c, 1])
            elif c == st[-1][0]:
                st[-1][1] += 1
            else:
                st.append(([c, 1]))
            
            if st[-1][1] == k:
                st.pop()
        res = ''
        for (c, cnt) in st:
            res += c * cnt
        return res
                    
