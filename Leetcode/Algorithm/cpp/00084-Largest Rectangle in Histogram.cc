class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> st;
        height.push_back(0);
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] <= height[st.top()]) {
                int now = st.top();
                st.pop();
                int left = st.empty()? 0: st.top() + 1;
                int right = i - 1;
                ans = max(ans, height[now] * (right - left + 1));
            }
            st.push(i);
        }
        return ans;
    }
};
