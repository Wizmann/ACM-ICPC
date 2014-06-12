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

/////////////


class Solution {
    static const int SIZE = 204800;
public:
    int largestRectangleArea(vector<int> &height) {
        int sz = height.size();
        for (int i =0; i < sz; i++) {
            left[i] = right[i] = i;
        }
        for (int i = 0; i < sz; i++) {
            while (left[i] - 1 >= 0 && height[left[i] - 1] >= height[i]) {
                left[i] = left[left[i] - 1];
            }
        }
        for (int i = sz - 1; i >= 0; i--) {
            while (right[i] + 1 < sz && height[right[i] + 1] >= height[i]) {
                right[i] = right[right[i] + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            ans = max(ans, height[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
    int left[SIZE];
    int right[SIZE];
};
