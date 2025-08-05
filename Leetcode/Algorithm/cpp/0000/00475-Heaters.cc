const int INF = 0x3f3f3f3f;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int l = 0;
        int r = INF;
        while (l <= r) {
            int m = (0LL + l + r) >> 1;
            if (check(houses, heaters, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
private:
    bool check(const vector<int>& houses, const vector<int>& heaters, int r) {
        auto hsiter = houses.begin();
        auto heiter = heaters.begin();
        
        while (hsiter != houses.end() && heiter != heaters.end()) {
            if (abs(*hsiter - *heiter) <= r) {
                hsiter++;
            } else {
                heiter++;
            }
        }
        
        return hsiter == houses.end();
    }
};
