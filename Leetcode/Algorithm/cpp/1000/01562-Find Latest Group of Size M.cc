// Should have a optimal solution with O(N)

struct Interval {
    Interval(int l_, int r_) {
        l = l_;
        r = r_;
    }
    
    bool operator < (const Interval& other) const {
        return other.r < l; 
    }

    int l, r;
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        set<Interval> st;
        st.insert(Interval(1, n));
        if (n == m) {
            return n;
        }
        for (int i = n - 1; i >= 0; i--) {
            int cur = arr[i];
            auto iter = st.find(Interval(cur, cur));
            assert(iter != st.end());
            int l = iter->l;
            int r = iter->r;
            st.erase(iter);
            if (l <= cur - 1) {
                st.insert(Interval(l, cur - 1));
                if (cur - l == m) {
                    return i;
                }
            }
            if (cur + 1 <= r) {
                st.insert(Interval(cur + 1, r));
                if (r - cur == m) {
                    return i;
                }
            }
        }
        assert(st.empty());
        return -1;
    }
};

