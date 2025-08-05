struct Interval {
    int l, r;
    
    bool operator < (const Interval& other) const {
        return r < other.l;
    }
};

class CountIntervals {
public:
    CountIntervals() {
        // pass
    }
    
    void add(int left, int right) {
        auto it = Interval {left, right};
        while (st.find(it) != st.end()) {
            auto iter = st.find(it);
            cnt -= iter->r - iter->l + 1;
            it.l = min(it.l, iter->l);
            it.r = max(it.r, iter->r);
            st.erase(iter);
        }
        st.insert(it);
        cnt += it.r - it.l + 1;
    }
    
    int count() {
        return cnt;
    }
private:
    set<Interval> st;
    int cnt = 0;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
