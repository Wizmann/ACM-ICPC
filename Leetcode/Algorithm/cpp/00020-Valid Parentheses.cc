class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        s = string("^") + s + string("$");
        for (int i = 0; i < s.size(); i++) {
            if (is_left(s[i])) {
                st.push(s[i]);
            } else {
                char x = get_reverse(s[i]);
                if (st.empty() || st.top() != x) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return true;
    }
    
    bool is_left(char x) {
        return x == '^' || x == '(' || x == '[' || x == '{';
    }
    
    char get_reverse(char x) {
        switch(x) {
            case '$': return '^';
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
        }
    }
};
