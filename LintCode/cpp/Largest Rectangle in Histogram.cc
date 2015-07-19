class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        height.push_back(-1);
        int n = height.size();
        stack<int> st;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int u = height[i];
            
            while (!st.empty() && height[st.top()] > u) {
                int v = st.top();
                st.pop();
                int l = st.empty()? 0: st.top() + 1;
                int r = i - 1;
                ans = max(ans, (r - l + 1) * height[v]);
            }
            
            st.push(i);
        }
        return ans;
    }
};

