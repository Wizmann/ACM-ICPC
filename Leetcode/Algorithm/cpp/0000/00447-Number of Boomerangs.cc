inline int power2(int x) {
    return x * x;
}

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j < n; j++) {
                int dis = power2(points[i].first - points[j].first) + power2(points[i].second - points[j].second);
                mp[dis]++;
            }
            for (auto p: mp) {
                ans += p.second * (p.second - 1);
            }
        }
        return ans;
    }
};
