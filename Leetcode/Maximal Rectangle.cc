class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int yy = matrix.size();
        int xx = matrix.empty()? 0: matrix[0].size();
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < xx; i++) {
            int ss = 0;
            for (int j = yy - 1; j >= 0; j--) {
                if (matrix[j][i] == '1') {
                    ss++;
                } else {
                    ss = 0;
                }
                sum[j][i] = ss;
            }
        }
        
        
        int ans = 0;
        for (int i = 0; i < yy; i++) {
            ans = max(ans, calc(sum[i], xx));
        }
        return ans;
    }
    
    int calc(int *s, int size) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= size; i++) {
            if (st.empty() || s[i] > s[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && s[i] <= s[st.top()]) {
                    int now = st.top();
                    st.pop();
                    ans = max(ans, s[now] * (st.empty()? i : i - st.top() - 1));
                }
                st.push(i);
            }
        }
        return ans;
    }
    static const int SIZE = 512;
    int sum[SIZE][SIZE];
};
