const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        
        int ans = 0;
        vector<int> vec;
        vec.resize(m);
        fill(vec.begin(), vec.end(), 0);
        vec.push_back(-1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <m; j++) {
                vec[j] = (matrix[i][j] == '0'? 0: vec[j] + 1);
            }
            ans = max(ans, _maxRect(vec));
        }
        return ans;
    }
private:
    int _maxRect(const vector<int>& vec) {
        size_t n = vec.size();
        stack<int> st;
        int ans = 0;
        
        for (size_t i = 0; i < n; i++) {
            while (!st.empty() && vec[i] <= vec[st.top()]) {
                int u = st.top();
                st.pop();
                int left = st.empty()? 0: st.top() + 1;
                int right = i - 1;
                ans = max(ans, vec[u] * (right - left + 1));
            }
            st.push(i);
        }
        return ans;
    }
};
