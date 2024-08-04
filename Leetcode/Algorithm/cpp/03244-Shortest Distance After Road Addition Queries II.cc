const int INF = 0x3f3f3f3f;

struct Interval {
    int left, right;

    bool operator < (const Interval& other) const {
        return right <= other.left;
    }
};

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m, -1);

        set<Interval> st;
        int sc = 0;
        int tot = n - 1;

        for (int i = 0; i < m; i++) {
            auto& query = queries[i];
            int a = query[0];
            int b = query[1];

            bool update = true;
            Interval itv = {a, b};
            // cout << a << ' ' << b << endl;
            while (true) {
                auto it = st.find(itv); 
                if (it == st.end()) {
                    break;
                }
                if (it->left <= a && it->right >= b) {
                    update = false;
                    break;
                }
                int aa = it->left;
                int bb = it->right;
                // cout << "> " << aa << ' ' << bb << endl;
                st.erase(it);
                tot = tot - 1 + (bb - aa);
            }
            // cout << tot << endl;
            if (update) {
                st.insert(itv);
                tot = tot - (b - a) + 1;
            }
            
            res[i] = tot;
        }

        return res;
    }
};
