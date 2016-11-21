typedef long long llint;
const llint INF = 0x3f3f3f3f3f3f3f3fLL;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        });
        
        llint l = -INF;
        llint r = -INF;
        int ans = 0;
        
        for (auto point: points) {
            llint pl = point.first;
            llint pr = point.second;
            
            if (pl > r) {
                if (r != -1) {
                    ans++;
                }
                l = pl;
                r = pr;
            } else {
                l = max(l, pl);
            }
        }
        return ans;
    }
};
