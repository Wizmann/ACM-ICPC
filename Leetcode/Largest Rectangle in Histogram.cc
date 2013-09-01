class Solution {
public:
    static const int INF = 1<<28;
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> st;
        int sz = height.size();
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (st.empty()) {
                st.push(i);
            } else {
                if (height[i] > height[st.top()]) {
                    st.push(i);
                } else {
                    while (!st.empty() && height[i] < height[st.top()]) {
                        int now = st.top();
                        st.pop();
                        ans = max(ans, height[now] *  (st.empty()? i: i - st.top() - 1));
                    }
                    st.push(i);
                }
            }
        }
        return ans;
    }
};
