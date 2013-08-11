class Solution {
public:
    static const int INF = 1<<28;
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        int y = matrix.size();
        if (y == 0) {
            return 0;
        }
        int x = matrix[0].size();
        int height[y+ 5][x + 5];
        
        memset(height, 0, sizeof(height));
        
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                height[i][j] = matrix[i][j] - '0';
                if (height[i][j] && i - 1 >= 0) {
                    height[i][j] += height[i-1][j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < y; i++) {
            ans = max(ans, solve(height[i], x));
        }
        return ans;
    }
    
    int solve(int height[], int x)
    {
        int ans = 0;
        stack<int> st;
        height[x] = 0;
        
        for (int i = 0; i <= x; i++) {
            if (st.empty() || height[i] > height[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && height[i] <= height[st.top()]) {
                    int t = st.top();
                    st.pop();
                    ans = max(ans, height[t] * (st.empty()? i: i - st.top() - 1));
                }
                st.push(i);
            }
        }
        return ans;
    }
};
