class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        set<pair<int, int> > st;
        for (const auto& mine: mines) {
            st.insert({mine[0], mine[1]});
        }
        
        dpv = vector<vector<int> >(N, vector<int>(N, 0));
        dph = vector<vector<int> >(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; i++) {
            int pre = 0;
            for (int j = 0; j < N; j++) {
                if (st.count({i, j}) != 0) {
                    dph[i][j] = -1;
                    pre = 0;
                } else {
                    pre++;
                    dph[i][j] = pre;
                }
            }
        }
        
        for (int j = 0; j < N; j++) {
            int pre = 0;
            for (int i = 0; i < N; i++) {
                if (st.count({i, j}) != 0) {
                    dpv[i][j] = -1;
                    pre = 0;
                } else {
                    pre++;
                    dpv[i][j] = pre;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dph[i][j] == -1) {
                    continue;
                }
                if (dpv[i][j] == -1) {
                    continue;
                }
                
                int u = min(dph[i][j], dpv[i][j]);
                u = min(u, N - i);
                u = min(u, N - j);
                
                int l = 1;
                int r = u;
                while (l <= r) {
                    int k = (l + r) >> 1;
                    int a = dph[i][j + k - 1] - dph[i][j];
                    int b = dpv[i + k - 1][j] - dpv[i][j];

                    if (a >= k - 1 && b >= k - 1) {
                        ans = max(ans, k);
                        l = k + 1;
                    } else {
                        r = k - 1;
                    }
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int> > dpv, dph;
};
