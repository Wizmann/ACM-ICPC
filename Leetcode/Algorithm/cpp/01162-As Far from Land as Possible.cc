const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<set<int> > stx(n), sty(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cur = grid[i][j];
                if (cur == 1) {
                    sty[i].insert(j);
                    stx[j].insert(i);
                }
            }
        }
        
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cur = grid[i][j];
                if (cur == 1) {
                    continue;
                }
                int mini = INF;
                for (int k = 0; k < n; k++) {
                    // cout << k << ' ' << sty[k].size() << endl;
                    if (sty[k].empty()) {
                        continue;
                    }
                    auto iter = sty[k].upper_bound(j);
                    if (iter != sty[k].end()) {
                        mini = min(mini, abs(k - i) + abs(*iter - j));
                    }
                    if (iter != sty[k].begin()) {
                        --iter;
                        mini = min(mini, abs(k - i) + abs(*iter - j));
                    }
                }
                
                for (int k = 0; k < n; k++) {
                    if (stx[k].empty()) {
                        continue;
                    }
                    auto iter = stx[k].upper_bound(j);
                    if (iter != stx[k].end()) {
                        mini = min(mini, abs(k - j) + abs(*iter - i));
                    }
                    if (iter != stx[k].begin()) {
                        --iter;
                        mini = min(mini, abs(k - j) + abs(*iter - i));
                    }
                }
                if (mini > res) {
                    res = mini;
                }
            }
        }
        if (res >= INF) {
            return -1;
        }
        return res;
    }
};
