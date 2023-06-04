struct Interval {
    int l, r;

    bool operator < (const Interval& other) const {
        return (other.r < l);
    }
};

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        colors = vector<int>(n, 0);
        vector<int> res;
        int tot = 0;

        for (const auto& q : queries) {
            int pos = q[0];
            int c = q[1];

            if (colors[pos] != 0) {
                auto iter = st.find({pos, pos});
                Interval interval = *iter;
                st.erase(iter);
                tot -= interval.r - interval.l;

                if (pos != interval.l) {
                    st.insert({interval.l, pos - 1});
                    tot += pos - 1 - interval.l;
                }
                if (pos != interval.r) {
                    st.insert({pos + 1, interval.r});
                    tot += interval.r - (pos + 1);
                }
            }

            colors[pos] = c;

            Interval interval = {pos, pos};

            if (pos - 1 >= 0 && colors[pos - 1] == c) {
                auto iter = st.find({pos - 1, pos - 1});
                interval.l = min(interval.l, iter->l);
                tot -= iter->r - iter->l;
                st.erase(iter);
            }
            if (pos + 1 < n && colors[pos + 1] == c) {
                auto iter = st.find({pos + 1, pos + 1});
                interval.r = max(interval.r, iter->r);
                tot -= iter->r - iter->l;
                st.erase(iter);
            }
            st.insert(interval);
            tot += interval.r - interval.l;
            res.push_back(tot);
            /*
            printf("[%d] ", res.back());
            for (int i = 0; i < n; i++) {
                printf("%d ", colors[i]);
            }
            puts("");
            */
        }

        return res;
    }
private:
    vector<int> colors;
    set<Interval> st;
};
