public class Solution {
    public int largestRectangleArea(int[] height) {
        Stack<Integer> st = new Stack<Integer>();
        int n = height.length;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int now = i < n? height[i]: 0;
            if (st.empty() || now > height[st.peek()]) {
                st.push(i);
                continue;
            }
            while (!st.empty() && now <= height[st.peek()]) {
                int p = st.pop();
                int left = st.empty()? 0: st.peek() + 1;
                int right = i - 1 ;
                ans = Math.max(ans, height[p] * (right - left + 1));
            }
            st.push(i);
        }
        return ans;
    }
}