struct MyInterval {
    int left, right;
    
    bool operator < (const MyInterval& other) const {
        return this->right < other.left;
    }
};

class RangeModule {
public:
    RangeModule() {
        // pass
    }
    
    void addRange(int left, int right) {
        right -= 1;
        
        MyInterval ll = {left - 1, left - 1};
        auto liter = st.find(ll);
        if (liter != st.end()) {
            left = liter->left;
        }
        
        MyInterval rr = {right + 1, right + 1};
        auto riter = st.find(rr);
        if (riter != st.end()) {
            right = riter->right;
        }
        
        doAddRange(left, right);
    }
    
    void doAddRange(int left, int right) {
        MyInterval newInterval = {left, right};
        while (true) {
            auto iter = st.find(newInterval);
            if (iter == st.end()) {
                break;
            }
            newInterval.left = min(newInterval.left, iter->left);
            newInterval.right = max(newInterval.right, iter->right);
            st.erase(iter);
        }
        st.insert(newInterval);
    }
    
    bool queryRange(int left, int right) {        
        right -= 1;
        MyInterval interval = {left, right};
        auto iter = st.find(interval);
        if (iter == st.end()) {
            return false;
        }
        
        return iter->left <= left && right <= iter->right;
    }
    
    void removeRange(int left, int right) {
        right -= 1;
        MyInterval newInterval = {left, right};

        while (true) {
            auto iter = st.find(newInterval);
            if (iter == st.end()) {
                break;
            }
            auto cur = *iter;
            st.erase(iter);
            
            if (cur.left < newInterval.left) {
                st.insert({cur.left, newInterval.left - 1});
            }
            if (cur.right > newInterval.right) {
                st.insert({newInterval.right + 1, cur.right});
            }
        }
    }
private:
    set<MyInterval> st;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
