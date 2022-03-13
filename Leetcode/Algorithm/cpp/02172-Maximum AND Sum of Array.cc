const int INF = 0x3f3f3f3f;

class KM {
public:
    KM(int n_, int m_) {
        n = n_;
        m = max(n_, m_);
        g = vector<vector<int>>(n, vector<int>(m, 0));
        visx = vector<bool>(n, false);
        visy = vector<bool>(m, false);
        lx = vector<int>(n, 0);
        ly = vector<int>(m, 0);
        linky = vector<int>(m, -1);
        slack = vector<int>(m, INF);
    }

    void SetWeight(int l, int r, int v) {
        assert(l < g.size());
        assert(r < g[l].size());
        g[l][r] = v;
    }

    int solve() {
        return km();
    }
private:
    bool dfs(int x) {
        assert(x < visx.size());
        visx[x] = true;
        for (int y = 0; y < m; y++) {
            assert(y < visy.size());
            if (visy[y]) {
                continue;
            }
            assert(x < lx.size());
            assert(y < ly.size());
            assert(x < g.size());
            assert(y < g[x].size());
            int t = lx[x] + ly[y] - g[x][y];
            assert(y < slack.size());
            if (!t) {
                assert(y < linky.size());
                visy[y] = true;
                if (linky[y] == -1 || dfs(linky[y])) {
                    linky[y] = x;
                    return true;
                }
            } else if (t < slack[y]) {
                slack[y] = t;
            }
        }
        return false;
    }

    int km() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                assert(i < lx.size());
                assert(i < g.size());
                assert(j < g[i].size());
                lx[i] = max(lx[i], g[i][j]);
            }
        }

        fill(ly.begin(), ly.end(), 0);

        for (int i = 0; i < n; i++) {
            fill(slack.begin(), slack.end(), INF);
            assert(slack.size() == m);
            assert(visx.size() == n);
            assert(visy.size() == m);
            while (true) {
                fill(visx.begin(), visx.end(), false);
                fill(visy.begin(), visy.end(), false);
                if (dfs(i)) {
                    break;
                }
                int d = INF;
                for (int j = 0; j < m; j++) {
                    if (!visy[j]) {
                        assert(j < slack.size());
                        d = min(d, slack[j]);
                    }
                }
                for (int j = 0; j < n; j++) {
                    assert(j < visx.size());
                    assert(j < lx.size());
                    if (visx[j]) {
                        lx[j] -= d;
                    }
                }
                for (int j = 0; j < m; j++) {
                    assert(j < visy.size());
                    assert(j < ly.size());
                    if (visy[j]) {
                        ly[j] += d;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            if (linky[i] != -1) {
                res += lx[linky[i]] + ly[i];
            }
        }
        return res;
    }

    int n, m;
    vector<vector<int> > g;
    vector<bool> visx;
    vector<bool> visy;
    vector<int> linky;
    vector<int> lx;
    vector<int> ly;
    vector<int> slack;
};

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = numSlots * 2 + 1;
        int m = nums.size();
        KM km(n, n);

        for (int i = 1; i <= numSlots; i++) {
            for (int j = 0; j < m; j++) {
                int v = nums[j];
                km.SetWeight(i * 2 - 1, j, i & v);
                km.SetWeight(i * 2, j, i & v);
            }
        }

        return km.solve();
    }
};
