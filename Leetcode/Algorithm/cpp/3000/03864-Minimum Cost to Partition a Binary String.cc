using llint = long long;

constexpr llint INF = 0x3f3f3f3f3f3f3f3fLL;

class Solution {
public:
    llint minCost(string s_, int encCost_, int flatCost_) {
        encCost = encCost_;
        flatCost = flatCost_;
        n = s_.size();
        s.resize(n);
        for (int i = 0; i < n; i++) {
            s[i] = s_[i] - '0';
            if (i - 1 >= 0) {
                s[i] += s[i - 1];
            }
        }
        return dfs(0, n - 1);
    }
private:
    int countItem(int l, int r) {
        int vl = l - 1 >= 0? s[l - 1]: 0;
        int vr = s[r];
        return vr - vl;
    }
    
    llint dfs(int l, int r) {
        int X = countItem(l, r);
        int L = r - l + 1;
        llint mini = INF;
        if (X == 0) {
            mini = min(mini, 1LL * flatCost);
        } else {
            mini = min(mini, 1LL * L * X * encCost);
            if (l != r && L % 2 == 0) {
                int m = (l + r) / 2;
                mini = min(mini, dfs(l, m) + dfs(m + 1, r));
            }
        }
        return mini;
    }
private:
    int n;
    vector<int> s;
    int encCost;
    int flatCost;
};
