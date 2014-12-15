class Solution {
public:
    int maximumGap(vector<int> &num) {
        int mini = INF;
        int maxi = -INF;
        int n = num.size();
        if (n <= 1) {
            return 0;
        }
        for (auto i: num) {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        int dis = (maxi - mini + n - 1) / n;
        _vec.clear();
        _vec.resize(n);
        for (auto& p: _vec) {
            p.first = INF;
            p.second = -INF;
        }
        for (auto i: num) {
            int u = (i - mini) / dis;
            _vec[u].first  = min(_vec[u].first,  i);
            _vec[u].second = max(_vec[u].second, i);
        }
        
        int ans = 0;
        int prev = _vec[0].second;
        for (int i = 1; i < n; i++) {
            if (_vec[i].first != INF) {
                ans = max(ans, _vec[i].first - prev);
            }
            if (_vec[i].second != -INF) {
                prev = _vec[i].second;
            }
        }
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
    vector<pair<int, int> > _vec;
};
