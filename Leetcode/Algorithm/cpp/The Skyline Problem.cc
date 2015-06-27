struct ScanLine {
    int pos;
    int nr;
    int status;
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();

        vector<ScanLine> scanlines;

        for (int i = 0; i < n; i++) {
            auto& b = buildings[i];
            scanlines.push_back({b[0], i, 1});
            scanlines.push_back({b[1], i, -1});
        }
        
        sort(scanlines.begin(), scanlines.end(), [](const ScanLine& sa, const ScanLine& sb) {
            return sa.pos < sb.pos;
        });
        
        multiset<int> st;
        st.insert(0);
        
        vector<pair<int, int>> res;
        
        int preh = 0;
        for (int i = 0; i < n * 2; /* pass */) {
            int cur = scanlines[i].pos;
            
            while (i < n * 2 && scanlines[i].pos == cur) {
                auto& s = scanlines[i];
                if (s.status == 1) {
                    st.insert(buildings[s.nr][2]);
                } else {
                    auto iter = st.find(buildings[s.nr][2]);
                    st.erase(iter);
                }
                i++;
            }
            int curh = *st.rbegin();
            if (preh != curh) {
                res.push_back({cur, curh});
                preh = curh;
            }
        }
        return res;
    }
};
