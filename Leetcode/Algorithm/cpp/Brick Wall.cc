class Solution {
public:
    int leastBricks(vector<vector<int>>& walls) {
        map<int, int> mp;
        for (const auto& wall: walls) {
            int sum = 0;
            int m = wall.size();
            for (int i = 0; i < m - 1; i++) {
                sum += wall[i];
                // cout << sum << endl;
                mp[sum]++;
            }
        }
        
        int n = walls.size();
        int ans = n;
        for (auto kvpair: mp) {
            ans = min(ans, n - kvpair.second);
        }
        return ans;
    }
};
