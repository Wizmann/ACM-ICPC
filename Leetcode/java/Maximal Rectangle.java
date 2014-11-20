public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].length;
        if (m == 0) {
            return 0;
        }
        int graph[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }
                graph[i][j] = sum;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            Stack<Integer> st = new Stack<Integer>();
            for (int j = 0; j <= n; j++) {
                int now = j == n? 0: graph[j][i];
                if (st.empty() || graph[st.peek()][i] < now) {
                    st.push(j);
                    continue;
                }
                while (!st.empty() && graph[st.peek()][i] >= now) {
                    int prev = st.pop();
                    int left = st.empty()? 0: st.peek() + 1;
                    int right = j - 1;
                    ans = Math.max(ans, graph[prev][i] * (right - left + 1));
                }
                st.push(j);
            }
        }
        return ans;
    }
}
