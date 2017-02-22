class Solution {
public:
    int countArrangement(int N) {
        nums.resize(N + 100);
        visited = vector<char>(N + 100, 0);
        ans = 0;
        dfs(0, N);
        return ans;
    }
private:
    void dfs(int cur, int n) {
        if (cur == n) {
            ans++;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            if (i % (cur + 1) == 0 || (cur + 1) % i == 0) {
                nums[cur] = i;
                visited[i] = 1;
                dfs(cur + 1, n);
                
                visited[i] = 0;
            }
        }
    }
private:
    int ans;
    vector<int> nums;
    vector<char> visited;
};
