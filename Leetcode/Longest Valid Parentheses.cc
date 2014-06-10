class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, last = -1;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    last = i;
                } else {
                    st.pop();
                    if (st.empty()) {
                        ans = max(ans, i - last);
                    } else {
                        ans = max(ans, i - st.top());   
                    }
                }
            }
        }
        return ans;
    }
};
