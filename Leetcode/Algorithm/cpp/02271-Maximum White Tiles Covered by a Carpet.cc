struct Interval {
    int l, r, prefix;
    bool operator < (const Interval& it) const { return r < it.l; }
};

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        multiset<Interval> st;
        sort(tiles.begin(), tiles.end(), [](const auto& t1, const auto& t2) { return t1[0] < t2[0]; });

        int presum = 0;
        for (const auto& t : tiles) {
            int a = t[0];
            int b = t[1];
            st.insert({a, b, presum});
            presum += b - a + 1;
        }

        int res = 0;
        for (const auto& t : tiles) {
            int l = t[0], r = l + carpetLen - 1;
            auto p = st.equal_range({l, r, -1});

            auto lit = p.first, rit = p.second;

            if (lit == st.end() || rit == st.begin()) {
                continue;
            }
            
            --rit;
            if (lit == rit) {
                res = max(res, min(carpetLen, lit->r - lit->l + 1));
            } else {
                int u = rit->prefix - lit->prefix;
                u += min(rit->r, r) - rit->l + 1;
                res = max(res, u);
            }
        }
        return res;
    }
};
