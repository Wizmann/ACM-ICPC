class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> st;
        for (size_t i = 0; i < tokens.size(); i++) {
            if (is_symbol(tokens[i])) {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push(calc(a, b, tokens[i]));
            } else {
                st.push(tokens[i]);
            }
        }
        return atoi(st.top().c_str());
    }
    
    bool is_symbol(const string& token) {
        if (token == "+" || 
                token == "-" ||
                token == "*" ||
                token == "/") {
            return true;
        } else {
            return false;
        }
    }
    
    string calc(const string& a_str, const string& b_str, const string& symbol) {
        int b = atoi(a_str.c_str());
        int a = atoi(b_str.c_str());
        int c = 0;
        if (symbol == "+") {
            c = a + b;
        } else if (symbol == "-") {
            c = a - b;
        } else if (symbol == "*") {
            c = a * b;
        } else if (symbol == "/") {
            c = a / b;
        }
        std::ostringstream oss;
        oss << c;
        return oss.str();
    }
};
