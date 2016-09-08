class Solution(object):
    def lengthLongestPath(self, filetree):
        ft = filetree.split('\n')
        st = []
        ans = 0
        for path in ft:
            d = path.count('\t')
            while d < len(st):
                st.pop()
            
            st.append(len(path.replace('\t', '')))
            if '.' in path:
                ans = max(ans, sum(st) + len(st) - 1)
        return ans
