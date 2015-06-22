class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        st = []
        pair = {
            ']': '[',
            ')': '(',
            '}': '{'
        }
        for c in s:
            if c in ['(', '{', '[']:
                st.append(c)
            else:
                if not st or st[-1] != pair[c]:
                    return False
                else:
                    st.pop()
        return True if not st else False
