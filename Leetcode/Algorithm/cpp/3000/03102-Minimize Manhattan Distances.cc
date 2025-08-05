const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> st1, st2;
        for (const auto& p : points) {
            int x = p[0];
            int y = p[1];
            st1.insert({x + y});
            st2.insert({x - y});
        }

        int ans = INF;
        for (const auto& p : points) {
            int x = p[0];
            int y = p[1];
            int maxi = 0;

            auto iter = st1.find({x + y});
            st1.erase(iter);
            maxi = max(maxi, abs(*st1.begin() - *st1.rbegin()));

            auto jter = st2.find({x - y});
            st2.erase(jter);
            maxi = max(maxi, abs(*st2.begin() - *st2.rbegin()));

            st1.insert({x + y});
            st2.insert({x - y});

            ans = min(ans, maxi);
        }
        return ans;
    }
};
