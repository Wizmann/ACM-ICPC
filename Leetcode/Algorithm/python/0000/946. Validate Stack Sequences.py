class Solution(object):
    def validateStackSequences(self, pushed, popped):
        st = []
        for pp in popped:
            while pushed and (not st or st[-1] != pp):
                st.append(pushed.pop(0))
                
            if not st or st[-1] != pp:
                return False
            
            st.pop()
        return True
