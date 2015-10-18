class Solution(object):
    def simplifyPath(self, path):
        path = filter(lambda x: x, path.split("/"))
        st = []
        for item in path:
            if item == '.':
                continue
            elif item == '..':
                if st:
                    st.pop()
            else:
                st.append(item)

        return '/' + '/'.join(st)
        
